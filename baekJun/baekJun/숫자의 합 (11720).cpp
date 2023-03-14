#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string A;
	int N, sum = 0;
	cin >> N;
	cin >> A;
	for (int i = 0; i < N; i++) {
		sum += A[i];
	}
	sum -= 48 * N;
	cout << sum;
}