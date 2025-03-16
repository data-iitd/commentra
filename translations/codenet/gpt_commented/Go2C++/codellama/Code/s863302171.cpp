#include <iostream>
using namespace std;

int main() {
	// Declare a variable to hold the input string
	string n;
	
	// Read input from the user and store it in variable n
	cin >> n;
	
	// Loop through the first three characters of the input string
	for (int i = 0; i < 3; i++) {
		// Check if the current character is '7'
		if (n[i] == '7') {
			// If '7' is found, print "Yes" and exit the program
			cout << "Yes" << endl;
			return 0;
		}
	}
	
	// If '7' is not found in the first three characters, print "No"
	cout << "No" << endl;
	
	return 0;
}

