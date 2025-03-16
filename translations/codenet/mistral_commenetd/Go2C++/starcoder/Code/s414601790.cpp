// C++ code by <NAME>

#include <bits/stdc++.h>
using namespace std;

int main() {
	// Variable declaration and initialization
	int n;
	string s;

	// Reading input from the user
	cin >> n >> s;

	// Variable declaration and initialization for maximum count and current count
	int max = 0;
	int cnt = 0;

	// Iterating through each character in the string's'
	for (int i = 0; i < s.length(); i++) {
		// Checking if the character is 'I'
		if (s[i] == 'I') {
			// Incrementing the current count
			cnt++;
		} else {
			// Decrementing the current count
			cnt--;
		}

		// Updating the maximum count if the current count is greater
		if (cnt > max) {
			max = cnt;
		}
	}

	// Printing the maximum count
	cout << max << endl;

// End of the code
}

Translate the above C++ code to Python and end with comment "