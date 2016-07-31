#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int start, end;
	cin >> start;
	cin >> end;

	int min, result = 0;
	double temp;
	int temp2;
	bool check = true;
	for (int i = start; i <= end; i++) {
		temp = sqrt(i);
		temp2 = temp * 1000;
		if (temp2 % 1000 == 0) {
			if (check) {
				min = i;
				check = false;
			}
			result += i;
		}
	}
	if (result == 0) {
		cout << "-1";
	}
	else {
		cout << result << endl;
		cout << min;
	}

	return 0;
}