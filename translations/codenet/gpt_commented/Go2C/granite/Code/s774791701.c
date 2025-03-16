
#include <stdio.h>

int main() {
	// Declare a variable to hold the input string
	char s[100];
	
	// Read input from the user and store it in the variable's'
	scanf("%s", s);

	// Initialize the base price
	int price = 700;
	
	// Iterate over each character in the input string
	for (int i = 0; s[i]!= '\0'; i++) {
		// Check if the character is 'o'
		if (s[i] == 'o') {
			// If it is 'o', increase the price by 100
			price += 100;
		}
	}
	
	// Print the final price after processing the input string
	printf("%d\n", price);
	
	// 