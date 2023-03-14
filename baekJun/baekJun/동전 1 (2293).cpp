#include <iostream>

using namespace std;

long long dp[10010] = { 1,0, };

int main(void) {
	int n, k, value[110] = { 0, };
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = value[i]; j <= k; j++) {
			dp[j] += dp[j - value[i]];
		}
	}
	cout << dp[k];

}