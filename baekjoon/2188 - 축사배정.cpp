#include<iostream>
using namespace std;

int cowNum, stableNum;
bool **cow;
int *stable;
bool *checked;

bool DFS(int cowLco)
{
	if (checked[cowLco])
		return false;
	checked[cowLco] = true;

	for (int i = 1, ii = stableNum + 1; i < ii; i++) {
		if (cow[cowLco][i] == true) {
			if (stable[i] == 0 || DFS(stable[i]) == true) {
				stable[i] = cowLco;
				return true;
			}
		}
	}
	return false;
}

void init_Check() {
	for (int i = 1, ii = cowNum + 1; i < ii; i++) {
		checked[i] = false;
	}
}

int main(void)
{
	cin >> cowNum;
	cin >> stableNum;

	cow = new bool *[cowNum + 1];  //소가 원하는 방 데이터 저장
	stable = new int[stableNum + 1]; //방에 어떤 소가 들어가는지 저장
	for (int i = 1, ii = stableNum + 1; i < ii; i++) {
		stable[i] = 0;
	}
	checked = new bool[cowNum + 1]; //소 확인했는지 저장

	int wants, roomNum;
	for (int i = 1, ii = cowNum + 1; i < ii; i++) {
		cow[i] = new bool[stableNum + 1];

		for (int j = 1, jj = stableNum + 1; j < jj; j++) {
			cow[i][j] = false;
		}

		cin >> wants;
		for (int j = 0; j < wants; j++) {
			cin >> roomNum;
			cow[i][roomNum] = true;
		}
	}

	int result = 0;
	for (int i = 1, ii = cowNum + 1; i < ii; i++) {
		init_Check();
		if (DFS(i))
			result++;

	}
	cout << result;
}
