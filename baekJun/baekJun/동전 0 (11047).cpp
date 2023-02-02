#include <iostream>
using namespace std;

int arr[11];

int main(void) {
	int N, K, ans = 0;
	int i;
	cin >> N >> K;
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}
	i--;
	for (i; i >= 0; i--) {
		ans += K / arr[i];
		K %= arr[i];
	}

	cout << ans;
}