#include <iostream>
#include<algorithm>
using namespace std;

bool cmp(int *data1, int*data2) {
	if (data1[1] == data2[1])
		return data1[0] < data2[0];
	else
		return data1[1] < data2[1];
}

int main() {
	int n;
	cin >> n;

	int **data = new int*[n];
	for (int i = 0; i < n; i++) {
		data[i] = new int[2];
		cin >> data[i][0];
		cin >> data[i][1];
	}
	if (n>1)
		sort(data, data + n, cmp);

	int count = 1, curr = 0;
	for (int i = 1; i < n; i++) {
		if (data[i][0] >= data[curr][1]) {
			curr = i;
			count++;
		}
	}
	cout << count;

	return 0;
}

