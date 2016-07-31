#include <iostream>
using namespace std;

int main() {
	int n;
	long numberOfCases[3], nextCases[3];
	cin >> n;

	//'00' is one case
	numberOfCases[0] = 1; //00
	numberOfCases[1] = 1; //01
	numberOfCases[2] = 1; //10

	for (int i = 2; i <= n; i++) {
		nextCases[0] = numberOfCases[0] + numberOfCases[1] + numberOfCases[2];
		nextCases[1] = numberOfCases[0] + numberOfCases[2];
		nextCases[2] = numberOfCases[0] + numberOfCases[1];

		numberOfCases[0] = nextCases[0] % 9901;
		numberOfCases[1] = nextCases[1] % 9901;
		numberOfCases[2] = nextCases[2] % 9901;
	}

	int result = (numberOfCases[0] + numberOfCases[1] + numberOfCases[2]) % 9901;
	cout << result;
	return 0;
}