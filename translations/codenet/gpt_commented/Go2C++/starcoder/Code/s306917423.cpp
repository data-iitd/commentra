#include <iostream>

using namespace std;

int main() {
	// Declare a variable to hold the input string
	string s;
	
	// Read input from the user and store it in the variable's'
	cin >> s;
	
	// Initialize a counter to keep track of the number of '1's in the string
	int ans = 0;
	
	// Iterate over each character in the input string
	for (int i = 0; i < s.length(); i++) {
		// Check if the current character is '1'
		if (s[i] == '1') {
			// Increment the counter if '1' is found
			ans++;
		}
	}
	
	// Print the total count of '1's found in the input string
	cout << ans << endl;
}

