
#include <iostream>

using namespace std;

int n, ans;

const int arraySize = 101;

int a[arraySize][arraySize];

void findAns(int i, int j, int sum) {
	if (i == 1 && j == n-1 && sum+a[i][j] > ans) {
		ans = sum + a[i][j];
		return;
	}
	if (i == 0) {
		findAns(i+1, j, sum+a[i][j]);
	}
	if (j+1 < n) {
		findAns(i, j+1, sum+a[i][j]);
	}
}
int main() {

	cin >> n;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	findAns(0, 0, 0);
	cout << ans << endl;
}

