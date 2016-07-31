#include <iostream>
#define max(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

int main() {
	int n;
	cin >> n;

	int *input = new int[n];
	int *number = new int[n + 2];
	int *nextnumber = new int[n + 2];

	cin >> number[0];

	cin >> input[0];
	cin >> input[1];

	number[1] = number[0] + input[0];
	number[2] = number[0] + input[1];
	number[0] = 0;

	int inputNum = 2;

	for (int i = 2; i < n; i++) {
		inputNum++;

		for (int i = 0; i<inputNum; i++)
			cin >> input[i];

		number[inputNum] = 0;

		for (int j = 0; j<inputNum; j++)
			nextnumber[j + 1] = input[j] + max(number[j], number[j + 1]);

		for (int j = 1; j <= inputNum; j++)
			number[j] = nextnumber[j];

	}

	int result = 0;

	for (int i = 1; i <= inputNum; i++) {
		if (result < number[i])
			result = number[i];
	}

	cout << result;
	return 0;
}