#include <iostream>
using namespace std;

int main() {
	int n, n2;
	int min;
	long long result, area;
	cin >> n;
	n2 = n + 1;
	if (n == 1) {
		cin >> n;
		cout << n;
	}
	else {

		long long *D = new long long[n + 2];
		D[0] = -1;

		cin >> D[1];
		min = D[1];
		for (int i = 2; i < n2; i++) {
			cin >> D[i];
			if (min > D[i])
				min = D[i];
		}
		D[n + 1] = -1;

		result = n*min;
		int width, start, end;


		for (int i = 1; i < n; i++) {
			width = 1;
			start = i;
			end = i + 1;
			if (D[end] >= D[start]) {
				if (D[start] == min) {
					continue;
				}
				while (end != n + 1)
				{
					if (D[start] < D[end]) {
						width++;
						end++;
					}
					else if (D[start] == D[end]) {

						width++;
						end++;
					}
					else {
						break;
					}
				}
				start = i;
				end = i - 1;
				while (D[start] <= D[end])
				{
					width++;
					end--;
					if (end == 0)
						break;
				}
				area = width*D[start];
			}
			else {
				// i max = n-1;
				if (i - 1 == 0) {
					start = end;
				}
				else {
					if (D[i - 1] < D[end]) {
						start = i - 1;
					}
					else {
						start = end;
					}
				}
				if (D[start] == min)
					continue;
				end = start + 1;

				while (D[start] <= D[end])
				{
					width++;
					end++;
					if (end == n2)
						break;
				}

				end = start - 1;
				while (D[start] <= D[end])
				{
					width++;
					end--;
					if (end == 0)
						break;
				}
				area = width*D[start];
				if (area < D[i])
					area = D[i];
			}
			if (result < area)
				result = area;

		}

		cout << result;
	}
	return 0;
}