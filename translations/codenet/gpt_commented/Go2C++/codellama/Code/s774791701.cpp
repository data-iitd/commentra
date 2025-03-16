
#include <iostream>

using namespace std;

int main() {
	// Declare a variable to hold the input string
	string s;
	
	// Read input from the user and store it in the variable 's'
	cin >> s;

	// Initialize the base price
	int price = 700;
	
	// Iterate over each character in the input string
	for (int i = 0; i < s.length(); i++) {
		// Check if the character is 'o'
		if (s[i] == 'o') {
			// If it is 'o', increase the price by 100
			price += 100;
		}
	}
	
	// Print the final price after processing the input string
	cout << price << endl;
	
	return 0;
}

