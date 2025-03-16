#include <bits/stdc++.h>

using namespace std;

int main() {
	// Declare a string variable to hold the input
	string s;
	// Read the input string from standard input
	cin >> s;
	// Get the length of the input string
	int l = s.length();
	// Initialize the answer as "AC" (Accepted)
	string ans = "AC";
	
	// Check if the first character is 'A'
	if (s[0]!= 'A') {
		// If not, set the answer to "WA" (Wrong Answer)
		ans = "WA";
	}
	
	// Initialize a counter for uppercase letters
	int cnt = 0;
	// Loop through the string starting from the second character
	for (int i = 1; i < l; i++) {
		// Check if the current character is an uppercase letter
		if (isupper(s[i])) {
			// Check if the uppercase letter is not at the second or last position
			// or if it is not 'C'
			if (i == 1 || i == l-1 || s[i]!= 'C') {
				// If any of the conditions are met, set the answer to "WA"
				ans = "WA";
			}
			// Increment the uppercase letter counter
			cnt++;
		}
	}
	
	// Check if there is exactly one uppercase letter (which should be 'C')
	if (cnt!= 1) {
		// If not, set the answer to "WA"
		ans = "WA";
	}
	
	// Print the final result
	cout << ans << endl;
}

