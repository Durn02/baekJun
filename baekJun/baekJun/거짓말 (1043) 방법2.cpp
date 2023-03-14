#include <iostream>
#include <vector>
using namespace std;

int people[51][51];
vector< vector<int> > v;
vector<int> know;

int Find(int key) {
	if (people[key][0] == key) return key;
	return Find(people[key][0]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	people[y][0] = x;
	if (people[x][1] == 1) {
		people[y][1] = 1;
	}
	if (people[y][1] == 1) {
		people[x][1] = 1;
	}
}

int main(void) {
	int N, M, a, b;
	int temp, prev;
	cin >> N >> M >> a;
	for (int i = 1; i <= N; i++) {
		people[i][0] = i;
	}
	for (int i = 0; i < a; i++) {
		cin >> temp;
		people[temp][1] = 1;
	}
	for (int i = 0; i < M; i++) {
		cin >> temp;
		for (int j = 0; j < temp; j++) {
			if (j > 0) {
				prev = b;
				cin >> b;
				Union(b, prev);
			}
			else {
				cin >> b;
			}
			know.push_back(b);
		}
		v.push_back(know);
		know.clear();
	}
	int ans = M;
	for (int i = 0; i < v.size(); i++) {
		int flag = 0;
		for (int j = 0; j < v[i].size(); j++) {
			if (people[v[i][j]][1] == 1 || people[Find(v[i][j])][1] == 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			ans--;
			continue;
		}
	}

	cout << ans;

}