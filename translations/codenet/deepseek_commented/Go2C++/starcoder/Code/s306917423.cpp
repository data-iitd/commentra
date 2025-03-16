#include <iostream>

using namespace std;

int main() {
	// Initialize a string variable to store the input
	string s;
	// Read input from the standard input and store it in the variable `s`
	cin >> s;
	
	// Initialize a variable to count the number of '1's in the input string
	int ans = 0;
	// Iterate over each character in the string `s`
	for (int i = 0; i < s.length(); i++) {
		// Check if the character is '1'
		if (s[i] == '1') {
			// Increment the count of '1's
			ans++;
		}
	}
	// Print the count of '1's to the standard output
	cout << ans << endl;
}

