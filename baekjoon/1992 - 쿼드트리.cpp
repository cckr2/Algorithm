#include <iostream>
#include <cmath>
#include <string>
using namespace std;
void print(int **table, int x, int y, int weight, int loc);

int main() {
	int n;
	string temp;
	cin >> n; //8

	if (n == 1) {
		cin >> temp;
		cout << temp;
	}
	else {
		int num = n*n;	 //64
		int size = n; //8
		int count = 0;

		while (size != 1) {
			size = size / 2;
			count++;
		}

		int **table = new int*[count];//3
		table[0] = new int[num];

		int for_temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			for_temp = i*n;
			for (int j = 0; j <n; j++) {
				if (temp[j] == '1')
					table[0][for_temp + j] = 1;
				else
					table[0][for_temp + j] = 0;
			}
		}

		num = num / 4;//16
		int weight = sqrt(num);
		size = weight * 2; //8

		for (int i = 1; i < count; i++) {
			table[i] = new int[num];
			for (int j = 0; j < weight; j++) {
				for_temp = 2 * size *j;
				for (int k = 0; k < weight; k++) {
					if (table[i - 1][for_temp + k * 2] == 1)
					{
						if ((table[i - 1][for_temp + k * 2] == table[i - 1][for_temp + k * 2 + 1]) && (table[i - 1][for_temp + k * 2] == table[i - 1][for_temp + k * 2 + size])
							&& (table[i - 1][for_temp + k * 2] == table[i - 1][for_temp + k * 2 + size + 1])) {
							table[i][j *weight + k] = 1;
						}
						else
							table[i][j *weight + k] = 2;
					}
					else if (table[i - 1][for_temp + k * 2] == 0)
					{
						if ((table[i - 1][for_temp + k * 2] == table[i - 1][for_temp + k * 2 + 1]) && (table[i - 1][for_temp + k * 2] == table[i - 1][for_temp + k * 2 + size])
							&& (table[i - 1][for_temp + k * 2] == table[i - 1][for_temp + k * 2 + size + 1])) {
							table[i][j *weight + k] = 0;
						}
						else
							table[i][j *weight + k] = 2;
					}
					else
						table[i][j *weight + k] = 2;
				}
			}

			num = num / 4;//16
			weight = sqrt(num);
			size = weight * 2; //8
		}
		for_temp = count - 1;

		if ((table[for_temp][0] == table[for_temp][1]) && (table[for_temp][0] == table[for_temp][2]) && (table[for_temp][0] == table[for_temp][3]))
			if (table[for_temp][0] == 1)
				cout << 1;
			else if (table[for_temp][0] == 0)
				cout << 0;
			else
				print(table, 0, 0, 2, for_temp);
		else
			print(table, 0, 0, 2, for_temp);
	}
	return 0;
}
void print(int **table, int x, int y, int weight, int loc) {
	cout << "(";
	int half_num = weight * 2;
	int start;
	for (int i = 0; i < 2; i++) {
		start = x*half_num + y * 2 + i*weight;
		for (int j = 0; j < 2; j++) {
			if (table[loc][start + j] == 1)
				cout << 1;
			else if (table[loc][start + j] == 0)
				cout << 0;
			else {

				print(table, (start + j) / weight, (start + j) % weight, weight * 2, loc - 1);

			}
		}
	}
	cout << ")";
}


