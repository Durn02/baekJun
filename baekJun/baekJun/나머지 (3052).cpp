#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int	arr[11], count = 10;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		arr[i] %= 42;
	}

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (arr[i] == arr[j]) {
				count--;
				break;
			}
		}
	}
	cout << count;

}