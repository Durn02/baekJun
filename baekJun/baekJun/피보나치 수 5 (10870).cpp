#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, pprev = 0, prev = 1, curr = 1;

	cin >> n;
	if (n == 0) {
		cout << 0;
	}
	else if (n == 1) {
		cout << 1;
	}
	else {
		for (int i = 2; i <= n; i++) {
			curr = prev + pprev;
			pprev = prev;
			prev = curr;
		}
		cout << curr;
	}
}