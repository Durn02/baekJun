#include <iostream>
using namespace std;

int find_min(int x) {
	int min = x;
	for (int i = 0; i < 3; i++) {
		x = x % 1000 * 10 + x / 1000;
		if (x < min) min = x;
	}
	return min;
}

int main(void) {
	int a, b, c, d;
	int ans = 0;
	cin >> a >> b >> c >> d;
	for (int i = 1111; i <= find_min(1000 * a + 100 * b + 10 * c + d); i++) {
		if (find_min(i) == i) {
			ans++;
		}
	}
	cout << ans;
}