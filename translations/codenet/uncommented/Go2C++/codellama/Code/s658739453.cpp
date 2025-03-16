#include <iostream>
#include <map>

using namespace std;

const int d = 1000000007;

int main() {
	int n, p;
	cin >> n >> p;

	map<long long, long long> mdans;
	for (int index = 0; index < p; index++) {
		long long n1;
		cin >> n1;
		mdans[n1] = n1;
	}

	long long dp[n+1];
	dp[0] = 1;
	dp[1] = 1;

	if (mdans.find(1) != mdans.end()) {
		dp[1] = 0;
	}

	for (int i = 2; i <= n; i++) {
		if (mdans.find(i) != mdans.end()) {
			continue;
		}
		dp[i] = (dp[i-1] + dp[i-2]) % d;

	}

	cout << dp[n] << endl;

	return 0;
}

