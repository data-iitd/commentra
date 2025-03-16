#include <bits/stdc++.h>

using namespace std;

int main() {
	// Set the input stream to read from standard input
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	// Read two integers from input: n (number of elements) and k (some parameter)
	int n, k;
	cin >> n >> k;
	
	// Read 'n' integers into slice 'a'
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	// Avoid unused variable error by assigning a value to the first element of 'a'
	a[0] = 0;
	
	// Initialize sum with the value of k and set ans to 1
	int sum = k;
	int ans = 1;
	
	// Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
	while (sum < n) {
		sum = sum - 1 + k; // Update sum by subtracting 1 and adding k
		ans++; // Increment the answer counter
	}
	
	// Print the final answer
	cout << ans << endl;
}

