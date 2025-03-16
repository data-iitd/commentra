#include <bits/stdc++.h>

using namespace std;

// Declare a scanner variable for reading input
std::cin.tie(0);
std::ios_base::sync_with_stdio(false);
std::istream_iterator<int> in(std::cin);
std::istream_iterator<int> end;
std::vector<int> v(in, end);

// Function to read the next string from input
string nextStr() {
	return std::string(std::istream_iterator<char>(std::cin), std::istream_iterator<char>());
}

// Function to read the next integer from input
int nextInt() {
	int n;
	std::cin >> n;
	return n;
}

int main() {
	// Read the number of integers to process
	int n = nextInt();

	// Initialize variables for the answer and the previous integer
	int ans = 0;
	int aPrev = 0;

	// Loop through each integer input
	for (int i = 0; i < n; i++) {
		int a = v[i]; // Read the next integer

		// Check conditions based on the current and previous integers
		switch (true) {
		case a > i || a > aPrev + 1: // If the current integer is greater than the index or previous integer + 1
			std::cout << -1 << std::endl; // Print -1 and exit if the condition is met
			return 0;
		case a == aPrev + 1: // If the current integer is exactly one more than the previous integer
			ans++; // Increment the answer
		default: // For all other cases
			ans += a; // Add the current integer to the answer
		}
		aPrev = a; // Update the previous integer to the current one
	}

	// Print the final answer
	std::cout << ans << std::endl;
}

