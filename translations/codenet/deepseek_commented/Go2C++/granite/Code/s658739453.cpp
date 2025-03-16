

#include <iostream>
#include <map>

using namespace std;

const int d = 1000000007;

int main() {
	int n, p;
	cin >> n >> p; // Read the values of n and p from standard input

	map<int64_t, int64_t> mdans;
	for (int index = 0; index < p; index++) {
		int64_t n1;
		cin >> n1; // Read each value into the map mdans
		mdans[n1] = n1;
	}

	vector<int64_t> dp(n+1, 0);
	dp[0] = 1; // Initialize the first element of dp vector
	dp[1] = 1; // Initialize the second element of dp vector

	if (mdans.find(1)!= mdans.end()) { // Check if the value 1 is in the map mdans
		dp[1] = 0; // Set dp[1] to 0 if 1 is in the map
	}

	for (int i = 2; i <= n; i++) {
		if (mdans.find(i)!= mdans.end()) { // Check if the current value i is in the map mdans
			continue; // Skip to the next iteration if i is in the map
		}
		dp[i] = (dp[i-1] + dp[i-2]) % d; // Calculate dp[i] as the sum of dp[i-1] and dp[i-2], modulo d
	}

	cout << dp[n] << endl; // Print the value at dp[n]

	return 0;
}

