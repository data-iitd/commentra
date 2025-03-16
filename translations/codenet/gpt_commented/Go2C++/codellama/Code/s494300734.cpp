#include <iostream>
#include <string>

using namespace std;

int main() {
	// Declare a variable to hold the input string
	string s;
	
	// Read a string input from the user
	cin >> s;
	
	// Initialize the answer variable with "No"
	string ans = "No";
	
	// Check if the first occurrence of 'C' is before the last occurrence of 'F'
	if (s.find("C") < s.rfind("F")) {
		// If true, set the answer to "Yes"
		ans = "Yes";
	}
	
	// Check if 'C' does not exist in the string
	if (s.find("C") == string::npos) {
		// If true, set the answer to "No"
		ans = "No";
	}
	
	// Print the final answer
	cout << ans << endl;
	
	return 0;
}

