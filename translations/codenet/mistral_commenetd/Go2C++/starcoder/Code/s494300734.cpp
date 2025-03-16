// C++ code by <NAME>

#include <iostream>
#include <string>

using namespace std;

int main() {
	// Initialize a variable s of type string and read a string input from the standard input
	string s;
	cin >> s;

	// Initialize a variable ans with the string value "No"
	string ans = "No";

	// Check if the index of the substring "C" in the string s is less than the index of the substring "F"
	if (s.find("C") < s.rfind("F")) {
		// If it is, then change the value of ans to "Yes"
		ans = "Yes";
	}

	// Check if the index of the substring "C" in the string s is less than 0
	if (s.find("C") < 0) {
		// If it is, then do not change the value of ans
	}

	// Print the value of ans to the standard output
	cout << ans << endl;
}

// End of the code

