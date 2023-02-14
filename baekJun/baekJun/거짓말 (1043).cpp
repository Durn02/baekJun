#include <iostream>
using namespace std;

/* �����[�����ȣ][���� ���� ����]
	ex) people[15][0] : 15��° ����̶� ����� ��� ��
		people[26][1] : 26��° ����� ���� ���� ����, �𸥴ٸ� 0
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
	int a; /*������ �ƴ� ��� ��*/
	int b; /*������ �ƴ� ��� ��ȣ*/
	int c; /*�� ��Ƽ�� ��*/
	int d = 0; /*�� ��Ƽ�� ��ȣ*/
	int prev, flag = 0, ans = 0;
	cin >> N >> M; // �Է� 1-1, 1-2
	ans = M;
	for (int i = 1; i <= N; i++) {
		people[i][0] = i;
	}
	cin >> a; // �Է� 2-1
	for (int i = 0; i < a; i++) { // �Է� 2-2~
		cin >> b;
		people[b][1] = 1;
	}
	for (int i = 0; i < M; i++) { // �Է� 3~
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