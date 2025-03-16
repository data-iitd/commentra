#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int getNextInt(istream& scanner) {
	string word;
	scanner >> word;
	return stoi(word);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	map<int, int> aa;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		aa[a] = 1;
	}

	vector<int> dp(n + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
			if (aa.find(i + ii) != aa.end()) {
				continue;
			}
			dp[i + ii] += dp[i];
			dp[i + ii] %= 1000000007;
		}
	}
	cout << dp[n] << endl;

	return 0;
}

