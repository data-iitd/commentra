#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string s;
	
	// Declare variables to store the input values.
	// `n` will store the integer input and `s` will store the string input.
	cin >> n;
	cin >> s;
	
	// Read an integer `n` and a string `s` from the standard input.
	// The `>>` operator is used to read an integer, and `>>` is used to read a string.
	
	// Print the number of occurrences of the substring "ABC" in the string `s`.
	// The `count` function is used to count the occurrences of the substring "ABC".
	cout << count(s.begin(), s.end(), 'A') << endl;
	
	return 0;
}

