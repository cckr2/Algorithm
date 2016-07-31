#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, money;
	cin >> n;
	cin >> money;

	int *coin = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	sort(coin, coin + n);

	int *count = new int[money + 1];
	for (int i = 1; i <= money; i++) {
		count[i] = 0;
	}
	count[0] = 1;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j <= money; j++) {
			if (j >= coin[i])
				count[j] += count[j - coin[i]];
		}
	}

	cout << count[money];
	return 0;
}
