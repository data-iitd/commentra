#include <bits/stdc++.h>

using namespace std;

const int d = 1000000007;

int main() {
	int n, p;
	cin >> n;
	cin >> p;

	map<int, int> mdans;
	for (int index = 0; index < p; index++) {
		int n1;
		cin >> n1;
		mdans[n1] = n1;
	}

	vector<int> dp(n+1, 1);
	dp[0] = 1;
	dp[1] = 1;

	if (mdans.find(1)!= mdans.end()) {
		dp[1] = 0;
	}

	for (int i = 2; i <= n; i++) {
		if (mdans.find(i)!= mdans.end()) {
			continue;
		}
		dp[i] = (dp[i-1] + dp[i-2]) % d;
	}

	cout << dp[n] << endl;
}

