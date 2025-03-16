
#include <bits/stdc++.h>

using namespace std;

const int d = 1000000007;

int main() {
	int n, p;
	cin >> n; // Read the value of n from standard input
	cin >> p; // Read the value of p from standard input

	map<int, int> mdans;
	for (int index = 0; index < p; index++) {
		int n1;
		cin >> n1; // Read each value into the map mdans
		mdans[n1] = n1;
	}

	vector<int> dp(n+1, 1); // Initialize the dp vector
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
}

