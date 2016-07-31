#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		int result;
		cin >> result;
		cout << result * result;
	}
	else {
		int temp, *D;
		D = new int[n];

		for (int i = 0; i < n; i++) {
			cin >> D[i];
		}
		sort(D, D + n);
		cout << D[0] * D[n - 1];
	}
	return 0;
}