#include <iostream>

using namespace std;

int main() {
	// Declare a variable 'n' of type string
	string n;

	// Read a string input from the user using cin
	cin >> n;

	// Initialize a loop counter 'i'
	int i = 0;

	// Check if the current character in the string 'n' is equal to '7'
	while (i < 3 && n[i]!= '7') {
		// If no, increment the loop counter
		i++;
	}

	// If no '7' is found in the first three characters, print "No"
	if (i == 3) {
		cout << "No" << endl;
	} else {
		// If yes, print "Yes"
		cout << "Yes" << endl;
	}

	return 0;
}

