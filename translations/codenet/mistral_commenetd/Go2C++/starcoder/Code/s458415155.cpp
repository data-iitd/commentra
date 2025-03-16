
#include <bits/stdc++.h>

using namespace std;

// Define a custom scanner type for reading input efficiently.
struct scanner {
	std::istream& stream;
	std::string buffer;
	scanner(std::istream& stream) : stream(stream) {}
	std::string get_word() {
		while (stream.peek() =='' || stream.peek() == '\n') {
			stream.get();
		}
		if (stream.peek() == EOF) {
			return "";
		}
		while (stream.peek()!= EOF && stream.peek()!='' && stream.peek()!= '\n') {
			buffer += stream.get();
		}
		return buffer;
	}
	int get_int() {
		std::string word = get_word();
		if (word == "") {
			return 0;
		}
		return atoi(word.c_str());
	}
	int get_int_slice(int n) {
		std::vector<int> vec;
		for (int i = 0; i < n; i++) {
			vec.push_back(get_int());
		}
		return vec;
	}
};

// Define helper functions for converting scanner output to int and int slice.
int get_int(scanner& sc) {
	return sc.get_int();
}

vector<int> get_int_slice(scanner& sc, int n) {
	return sc.get_int_slice(n);
}

// Define a helper function for calculating absolute value.
int iabs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

// Define the main function to solve the problem.
int solve(int n, vector<int> heights) {
	// Initialize a table t to store the minimum cost to reach each index.
	vector<int> t(n + 1, INT_MAX);
	// Set the initial value of the table to maximum integer.
	t[0] = 0;

	// Iterate through the array from index 1 to n-1.
	for (int i = 1; i < n; i++) {
		// Calculate the cost to reach index i from the previous index.
		int prevIndexCost = t[i - 1];
		// Update the cost to reach index i if the difference between heights is beneficial.
		int heightsDiff = heights[i] - heights[i - 1];
		if (heightsDiff < 0) {
			prevIndexCost += heightsDiff;
		} else {
			prevIndexCost -= heightsDiff;
		}
		// Update the cost to reach index i if the difference between previous index is beneficial.
		int prevIndex = i - 2;
		if (prevIndex >= 0) {
			int prevPrevIndexCost = t[prevIndex];
			int heightsDiff = heights[i] - heights[prevIndex];
			if (heightsDiff < 0) {
				prevPrevIndexCost += heightsDiff;
			} else {
				prevPrevIndexCost -= heightsDiff;
			}
			if (prevIndexCost < t[i]) {
				t[i] = prevIndexCost;
			}
			if (prevPrevIndexCost < t[i]) {
				t[i] = prevPrevIndexCost;
			}
		} else {
			// If the difference between previous index is not valid, only update the cost if the current difference is beneficial.
			if (prevIndexCost < t[i]) {
				t[i] = prevIndexCost;
			}
		}
	}

	// Return the minimum cost to reach the last index.
	return t[n - 1];
}

// Define the main function to read input and call the solve function.
int main() {
	// Initialize a scanner to read input from standard input.
	scanner sc(cin);
	// Read the number of test cases and iterate through each test case.
	int n = get_int(sc);
	for (int i = 0; i < n; i++) {
		// Read the number of heights and initialize an array to store them.
		int n = get_int(sc);
		vector<int> heights = get_int_slice(sc, n);
		// Call the solve function and print the result.
		int ans = solve(n, heights);
		cout << ans << endl;
	}
}

// The following comment can be added at the end of the code.

