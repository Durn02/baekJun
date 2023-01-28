#include <iostream>
#include <queue>
using namespace std;

int timer[5] = { 60, 10, -10, 1, -1 };
string dp[65];

bool right_is_smaller(string Current, string New) {
	int sumCurrent = 0, sumNew = 0;
	for (int i = 0; i < 5; i++) {
		sumCurrent += Current[i];
		sumNew += New[i];
	}
	if (sumCurrent != sumNew) {
		return sumCurrent > sumNew;
	}
	return Current > New;
}


int main(void) {
	int n, cur, nxt = 0;
	long long test_case;
	int answer[5] = { 0, };
	string New;

	//¼¼ÆÃ
	for (int i = 0; i <= 60; i++) {
		dp[i] = "99999";
	}
	queue<int> q;
	q.push(0);
	dp[0] = "00000";

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int i = 4; i >= 0; i--) {
			nxt = cur + timer[i];
			if (nxt > 60 || nxt < 0) continue;
			New = dp[cur];
			New[i]++;
			if (right_is_smaller(dp[nxt], New)) {
				dp[nxt] = New;
				q.push(nxt);
			}
		}

	}

	cin >> n;
	while (n--) {
		cin >> test_case;
		cout << test_case / 60 + (dp[test_case % 60][0] - '0') << " ";

		for (int i = 1; i < 5; i++) {
			cout << dp[test_case % 60][i] - '0' << " ";
		}
		cout << "\n";
	}

}