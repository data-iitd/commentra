#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<int, int> aa;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		aa[x] = 1;
	}

	vector<int> dp(n+1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int ii = 1; ii <= 2 && i+ii <= n; ii++) {
			if (aa.find(i+ii)!= aa.end()) {
				continue;
			}
			dp[i+ii] += dp[i];
			dp[i+ii] %= 1000000007;
		}
	}
	cout << dp[n] << endl;
	return 0;
}

