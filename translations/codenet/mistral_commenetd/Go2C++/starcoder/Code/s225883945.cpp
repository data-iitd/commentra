
#include <bits/stdc++.h>

using namespace std;

// Initialize a scanner for reading input from stdin
std::cin.tie(0);
std::ios_base::sync_with_stdio(false);
std::istream_iterator<int> input_iter(std::cin);
std::istream_iterator<char> input_iter_end;
std::back_insert_iterator<std::vector<int>> output_iter(a);

// Function to read a single word from the input
std::string next() {
	std::istream_iterator<int> it = input_iter;
	std::istream_iterator<int> end = input_iter_end;
	std::advance(it, 1);
	std::string s(it, end);
	input_iter = std::istream_iterator<int>(std::cin);
	return s;
}

// Function to read an integer from the input
int nextInt() {
	std::string s = next();
	int n;
	std::stringstream ss;
	ss << s;
	ss >> n;
	return n;
}

// Function to read n integers from the input
std::vector<int> nextInts(int n) {
	std::vector<int> a(n);
	std::copy(input_iter, input_iter + n, output_iter);
	input_iter = std::istream_iterator<int>(std::cin);
	return a;
}

// Main function
int main() {
	// Read number of elements n and the sum of elements k from the input
	int n, k;
	std::cin >> n >> k;

	// Initialize a slice of size n to store the input elements
	std::vector<int> a(n);

	// Assign a default value of 0 to the first element of the slice to avoid unused variable error
	a[0] = 0;

	// Initialize sum and answer variables
	int sum = 0, ans = 1;

	// Use a loop to find the number of times k can be subtracted from n to reach a non-negative value
	for (sum = 0; sum < n; sum = sum - 1 + k) {
		// Increment the answer variable for each iteration
		ans++;
	}

	// Print the answer
	std::cout << ans << std::endl;

	// End of code
}

