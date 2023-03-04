#include<iostream>
using namespace std;

int main(void) {
	int N, M, count = 0, sum = 0;
	long long arr[10002];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int l = 0, r = 1;
	sum = arr[l];
	while (l < r && r <= N) {
		if (sum == M) {
			count++;
			l++;
			sum = arr[l];
			r = l + 1;
		}
		else {
			sum += arr[r];
			r++;
		}
		if (sum>M) {
			l++;
			sum = arr[l];
			r = l + 1;
		}
	}
	cout << count;

}