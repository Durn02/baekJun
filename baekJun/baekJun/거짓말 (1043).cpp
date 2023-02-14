#include <iostream>
using namespace std;

/* 사람들[사람번호][진실 인지 여부]
	ex) people[15][0] : 15번째 사람이랑 연결된 노드 값
		people[26][1] : 26번째 사람이 진실 인지 여부, 모른다면 0
*/
int people[52][2];
int people_in_party[52][52];
int Find(int key) {
	if (people[key][0] == key) {
		return key;
	}
	return Find(people[key][0]);
}

void Union(int x, int y) {
	x = Find(x); // prev
	y = Find(y); // next
	people[x][0] = y;
	if (people[x][1] == 1) {
		people[y][1] = 1;
	}
	if (people[y][1] == 1) {
		people[x][1] = 1;
	}
}

int main(void) {
	int N, M;
	int a; /*진실을 아는 사람 수*/
	int b; /*진실을 아는 사람 번호*/
	int c; /*각 파티원 수*/
	int d = 0; /*각 파티원 번호*/
	int prev, flag = 0, ans = 0;
	cin >> N >> M; // 입력 1-1, 1-2
	ans = M;
	for (int i = 1; i <= N; i++) {
		people[i][0] = i;
	}
	cin >> a; // 입력 2-1
	for (int i = 0; i < a; i++) { // 입력 2-2~
		cin >> b;
		people[b][1] = 1;
	}
	for (int i = 0; i < M; i++) { // 입력 3~
		cin >> c;
		people_in_party[i][0] = c;
		for (int j = 1; j <= c; j++) {
			if (j > 1) {
				prev = d;
				cin >> d;
				Union(prev, d);
			}
			else {
				cin >> d;
			}
			people_in_party[i][j] = d;
		}

	}
	for (int i = 0; i < M; i++) {
		flag = 0;
		for (int j = 1; j <= people_in_party[i][0]; j++) {
			if (people[Find(people_in_party[i][j])][1] == 1 || people[people_in_party[i][j]][1] == 1) {
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