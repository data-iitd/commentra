
#include <stdio.h>
#include <stdlib.h>

int main() {
	// Declare a string variable to store user input
	char s[100];
	// Read input from the user and store it in the variable `s`
	scanf("%s", s);

	// Initialize the price variable with a starting value of 700
	int price = 700;
	// Loop through each character in the string `s`
	for (int i = 0; i < strlen(s); i++) {
		// Check if the current character is 'o'
		if (s[i] == 'o') {
			// If the character is 'o', add 100 to the price
			price += 100;
		}
	}
	// Print the final value of the price
	printf("%d", price);
}

