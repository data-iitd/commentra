
#include <iostream>
#include <map>

using namespace std;

// Define a constant for the modulo operation
const int d = 1000000007;

int main() {
	// Declare variables for the number of elements (n) and the number of blocked positions (p)
	int n, p;
	
	// Read the total number of elements (n) and the number of blocked positions (p) from input
	cin >> n >> p;

	// Create a map to store the blocked positions
	map<int64_t, int64_t> mdans;
	
	// Read the blocked positions and store them in the map
	for (int index = 0; index < p; index++) {
		int64_t n1;
		cin >> n1;
		mdans[n1] = n1;
	}

	// Initialize a vector to store the number of ways to reach each position
	vector<int64_t> dp(n+1, 0);
	
	// Base cases: There is 1 way to reach the 0th and 1st positions
	dp[0] = 1;
	dp[1] = 1;

	// If the first position is blocked, set the number of ways to reach it to 0
	if (mdans.find(1)!= mdans.end()) {
		dp[1] = 0;
	}

	// Iterate through positions from 2 to n to calculate the number of ways to reach each position
	for (int i = 2; i <= n; i++) {
		// If the current position is blocked, skip the calculation
		if (mdans.find(i)!= mdans.end()) {
			continue;
		}
		// Calculate the number of ways to reach the current position using the previous two positions
		dp[i] = (dp[i-1] + dp[i-2]) % d;
	}

	// Print the number of ways to reach the nth position
	cout << dp[n] << endl;

	return 0;
}
