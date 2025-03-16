
#include <bits/stdc++.h>

using namespace std;

int main() {
	// Creating a buffer scanner for reading input from stdin
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin.exceptions(cin.failbit);

	// Creating a buffer for storing the input
	string input;

	// Reading the first integer 'a' from stdin
	getline(cin, input);
	int a = stoi(input);

	// Reading the second integer 'b' from stdin
	getline(cin, input);
	int b = stoi(input);

	// Calculating the sum of 'a' and 'b'
	int ret = a + b;

	// Checking if the sum is less than the difference of 'a' and 'b'
	if (ret < (a - b)) {
		// If true, then update the value of'ret'
		ret = a - b;
	}

	// Checking if the sum is less than the product of 'a' and 'b'
	if (ret < (a * b)) {
		// If true, then update the value of'ret'
		ret = a * b;
	}

	// Printing the final value of'ret'
	cout << ret << endl;

	// End of the code
	return 0;
}

