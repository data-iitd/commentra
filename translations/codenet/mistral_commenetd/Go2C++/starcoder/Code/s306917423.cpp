#include <bits/stdc++.h>

using namespace std;

int main() {
	// Declaring a variable's' of type'string' to store the input string
	string s;

	// Reading the string input using 'cin >> s' statement
	cin >> s;

	// Declaring a variable 'ans' of type 'int' to store the answer
	int ans = 0;

	// Looping through each character 'c' in the string's'
	for (int i = 0; i < s.length(); i++) {
		// Checking if the current character 'c' is equal to '1'
		if (s[i] == '1') {
			// Incrementing the answer if the character is '1'
			ans++;
		}
	}

	// Printing the answer using 'cout << ans << endl' statement
	cout << ans << endl;

	// End of the code
}

