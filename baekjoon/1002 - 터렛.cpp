#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	int *result = new int[n];

	for (int k = 0; k < n; k++) {
		int D[6];

		for (int j = 0; j < 6; j++)
			cin >> D[j];

		double point_length = sqrt((D[3] - D[0])*(D[3] - D[0]) + (D[4] - D[1])*(D[4] - D[1]));
		double radius_sum = D[2] + D[5];

		if (point_length > radius_sum) {
			result[k] = 0;
		}
		else if (point_length == radius_sum) {
			result[k] = 1;
		}
		else if (point_length < radius_sum) {
			if ((D[5] + point_length < D[2]) || (D[2] + point_length < D[5])) {
				result[k] = 0;
			}
			else if ((D[5] + point_length == D[2]) || (D[2] + point_length == D[5])) {
				result[k] = 1;
			}
			else {
				result[k] = 2;
			}
		}

		if (point_length == 0.0) {
			if (D[2] == D[5])
				result[k] = -1;
			else
				result[k] = 0;
		}

	}

	for (int k = 0; k < n; k++) {
		cout << result[k] << endl;
	}

	return 0;
}