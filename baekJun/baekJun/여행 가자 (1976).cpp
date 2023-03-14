#include <iostream>
using namespace std;

int path[201][201];
int city[201];

int Find(int key) {
	if (city[key] == key) return key;
	return Find(city[key]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	city[y] = x;
}

int main(void) {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		city[i] = i;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> path[i][j];
			if (path[i][j]) {
				Union(i, j);
			}
		}
	}
	int plan = 0;
	int head, flag = 0;

	cin >> head;
	head = Find(city[head - 1]);

	for (int i = 0; i < M - 1; i++) {
		cin >> plan;
		if (Find(city[plan - 1]) != head) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}