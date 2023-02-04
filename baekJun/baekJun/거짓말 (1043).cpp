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
	int N, M; // N : 사람수, M : 파티수
	int truth_num; // 진실을 아는 사람 수
	int a, b, c;
	int know_person[51] = { 0, }; // 진실을 아는 사람 목록
	int party_people[51][51] = {0,}; //파티 명단
	int party_exagg[51] = { 0, }; //과장가능 파티

	cin >> N >> M;
	cin >> truth_num;
	for (int i = 0; i < truth_num; i++) {
		cin >> a;
		know_person[i] = a;
	}

	for (int i = 0; i < M; i++) {
		cin >> b; //파티 참가원 수
		for (int j = 0; j < b; j++) {
			cin >> c; //참가자 번호
			party_people[i][j] = c;
			if (!find(know_person, truth_num, c)) { //진실을 아는 사람이 없다면
				party_exagg[j] = 1; //j번째 파티는 거짓말 가능
			}
		}


	}
}