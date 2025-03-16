
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream fp;
	if (cin.rdbuf()->in_avail() == 0) {
		fp.open("input.txt");
	}
	string line;
	int n;
	getline(fp, line);
	stringstream ss(line);
	ss >> n;
	vector<int> mm(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	for (int i = 0; i < n; i++) {
		getline(fp, line);
		stringstream ss(line);
		ss >> mm[i] >> mm[i + 1];
	}

	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			for (int k = i; k <= j - 1; k++) {
				int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
				if (dp[i][j] == 0 || dp[i][j] > d) {
					dp[i][j] = d;
				}
			}
		}
	}

	cout << dp[1][n] << endl;

	return 0;
}

