#include <iostream>
#include <string>

int main() {
	// Declare a variable to hold the input string
	std::string s;
	
	// Read input from the user and store it in the variable's'
	std::cin >> s;

	// Initialize the base price
	int price = 700;
	
	// Iterate over each character in the input string
	for (auto c : s) {
		// Check if the character is 'o'
		if (c == 'o') {
			// If it is 'o', increase the price by 100
			price += 100;
		}
	}
	
	// Print the final price after processing the input string
	std::cout << price << std::endl;
}

