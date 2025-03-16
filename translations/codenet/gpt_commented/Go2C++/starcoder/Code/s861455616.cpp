#include <iostream>

using namespace std;

int main() {
	// Declare a variable to hold the input string
	string s;
	
	// Read input from the user and store it in the variable's'
	cin >> s;
	
	// Check if the length of the string is at least 4 characters 
	// and if the first four characters are "YAKI"
	if (s.length() >= 4 && s.substr(0, 4) == "YAKI") {
		// If the condition is true, print "Yes"
		cout << "Yes" << endl;
	} else {
		// If the condition is false, print "No"
		cout << "No" << endl;
	}
}

