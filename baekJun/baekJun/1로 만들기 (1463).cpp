#include <iostream>
#include <queue>

using namespace std;

int dp[1000001];
int mov[3] = { 1, 2, 3 };

int main(void) {
	int curr, next, N;
	queue<int> q;
	q.push(1);

	cin >> N;

	while (!q.empty()) {
		curr = q.front();
		q.pop();

		if (curr == N) break;

		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				next = curr + mov[0];
			}
			else {
				next = curr * mov[i];
			}
			if (next > N) continue;

			if (dp[next] == 0) {
				dp[next] = dp[curr] + 1;
			}
			else continue;
			q.push(next);
		}
	}
	cout << dp[N];
}