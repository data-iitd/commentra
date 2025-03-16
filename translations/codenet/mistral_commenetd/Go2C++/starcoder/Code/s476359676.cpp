
#include <bits/stdc++.h>

using namespace std;

// Initialize a scanner for reading input from stdin
std::cin.tie(0);
std::ios_base::sync_with_stdio(false);
std::istream_iterator<string> input_iter(std::cin);
std::istream_iterator<char> end_iter;
std::istream_iterator<string> input_line(input_iter, end_iter);
std::istream_iterator<string> end_line;

// Function to read the next integer
int nextInt() {
	int n = 0;
	while (*input_iter!= '\n') {
		n = n*10 + *input_iter - '0';
		input_iter++;
	}
	input_iter++;
	return n;
}

// Main function to read input and process it
int main() {
	// Read the number of test cases
	int n = nextInt();

	// Initialize variables for processing the input
	int ans = 0;
	int aPrev = 0;

	// Process each test case
	for (int i = 0; i < n; i++) {
		// Read the next integer as 'a'
		int a = nextInt();

		// Check if 'a' is valid based on the conditions in the problem statement
		switch {
		case a > i || a > aPrev+1: // 'a' is not valid, print -1 and exit
			cout << -1 << endl;
			return 0;
		case a == aPrev+1: // Increment the answer if 'a' is consecutive with the previous number
			ans++;
		default: // Add 'a' to the answer if it's not consecutive but greater than the previous number
			ans += a;
		}

		// Update the previous number
		aPrev = a;
	}

	// Print the final answer
	cout << ans << endl;

	// End of code


