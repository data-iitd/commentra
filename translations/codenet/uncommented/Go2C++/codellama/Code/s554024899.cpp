
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;
	cin >> x >> y;
	vector<vector<int>> a = { {1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2} };
	int xt, yt;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			if (x == a[i][j]) {
				xt = i;
			}
			if (y == a[i][j]) {
				yt = i;
			}
		}
	}
	if (xt == yt) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}

