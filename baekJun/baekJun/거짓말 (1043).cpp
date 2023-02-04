#include <iostream>
#include <vector>
using namespace std;

bool find(int arr[], int len, int key) {
	for (int i = 0; i < len; i++) {
		if (arr[i] == key) {
			return true;
		}
	}
	return false;
}

int main(void) {
	int N, M; // N : �����, M : ��Ƽ��
	int truth_num; // ������ �ƴ� ��� ��
	int a, b, c;
	int know_person[51] = { 0, }; // ������ �ƴ� ��� ���
	int party_people[51][51] = {0,}; //��Ƽ ���
	int party_exagg[51] = { 0, }; //���尡�� ��Ƽ

	cin >> N >> M;
	cin >> truth_num;
	for (int i = 0; i < truth_num; i++) {
		cin >> a;
		know_person[i] = a;
	}

	for (int i = 0; i < M; i++) {
		cin >> b; //��Ƽ ������ ��
		for (int j = 0; j < b; j++) {
			cin >> c; //������ ��ȣ
			party_people[i][j] = c;
			if (!find(know_person, truth_num, c)) { //������ �ƴ� ����� ���ٸ�
				party_exagg[j] = 1; //j��° ��Ƽ�� ������ ����
			}
		}


	}
}