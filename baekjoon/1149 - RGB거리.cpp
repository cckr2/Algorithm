#include <iostream>
#define min(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;

int main() {
	int n;
	long input[3], color[3], nextcolor[3];
	cin >> n;

	cin >> color[0];
	cin >> color[1];
	cin >> color[2];

	for (int i = 1; i < n; i++) {
		cin >> input[0];
		cin >> input[1];
		cin >> input[2];

		nextcolor[0] = input[0] + min(color[1], color[2]);
		nextcolor[1] = input[1] + min(color[0], color[2]);
		nextcolor[2] = input[2] + min(color[0], color[1]);

		color[0] = nextcolor[0];
		color[1] = nextcolor[1];
		color[2] = nextcolor[2];
	}

	long result = min(color[0], min(color[1], color[2]));
	cout << result;
	return 0;
}