#include <iostream>

using namespace std;

const int Max_num = 16;
const int INF = 987654321;

int N, cost[Max_num][Max_num];
int dp[Max_num][1 << Max_num];

int TSP(int curr, int visited) {
	if (visited == (1 << N) - 1) {
		if (cost[curr][0] != 0) {
			return cost[curr][0];
		}
		else {
			return INF;
		}
	}

	int& ret = dp[curr][visited];
	if (ret != -1) {
		return ret;
	}

	ret = INF;
	for (int next = 0; next < N; next++) {
		if (visited & (1 << next) || cost[curr][next] == 0) {
			continue;
		}
		ret = min(ret, cost[curr][next] + TSP(next, visited | (1 << next)));
	}

	return ret;
}


int main(void) {
	int ans;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	ans = TSP(0, 1);
	cout << ans;

}