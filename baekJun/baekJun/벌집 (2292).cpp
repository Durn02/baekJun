#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, sum_up = 1, i=1;
	cin >> N;
	while (N > sum_up) {
		sum_up += 6 * i;
		i++;
	}
	cout << i;

}