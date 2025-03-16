
#include <bits/stdc++.h>

using namespace std;

const int d = 1000000007; // Define a constant 'd' as a 32-bit integer

int main() {
	// Initialize variables
	int n, p;

	cin >> n; // Read the first integer 'n' from the standard input
	cin >> p; // Read the second integer 'p' from the standard input

	map<int, int> mdans; // Initialize an empty map'mdans' for storing distinct numbers

	// Read 'p' distinct numbers from the standard input and store them in the map'mdans'
	for (int index = 0; index < p; index++) {
		int n1;
		cin >> n1;
		mdans[n1] = n1; // Store the number 'n1' in the map'mdans' with its own key
	}

	vector<int> dp(n + 1, 0); // Initialize an array 'dp' of size 'n+1' with a default value of '0'
	dp[0] = 1; // Initialize the first element of the array 'dp' with a value of '1'
	dp[1] = 1; // Initialize the second element of the array 'dp' with a value of '1'

	// Initialize the third element of the array 'dp' with a value of '0' if the number '1' is present in the map'mdans'
	if (mdans.find(1)!= mdans.end()) {
		dp[1] = 0;
	}

	// Calculate the remaining elements of the array 'dp' using the previous elements
	for (int i = 2; i <= n; i++) {
		if (mdans.find(i)!= mdans.end()) {
			continue; // Skip the current iteration if the number 'i' is present in the map'mdans'
		}
		dp[i] = (dp[i - 1] + dp[i - 2]) % d; // Calculate the current element of the array 'dp' as the sum of the previous two elements modulo 'd'
	}

	// Print the final result
	cout << dp[n] << endl; // Print the value of the last element of the array 'dp'
}

