#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Create a new scanner to read input from standard input (os.Stdin)
	char s[100];
	fgets(s, 100, stdin);
	
	// Calculate the difference between lowercase and uppercase letters
	int d = 'a' - 'A';
	
	// Iterate over each rune (character) in the input string
	for (int i = 0; i < strlen(s); i++) {
		// Initialize a variable to hold the modified character
		char rr = s[i];
		
		// Check if the character is an uppercase letter
		if ('A' <= s[i] && s[i] <= 'Z') {
			// Convert uppercase to lowercase by adding the difference
			rr = s[i] + d;
		} else if ('a' <= s[i] && s[i] <= 'z') {
			// Convert lowercase to uppercase by subtracting the difference
			rr = s[i] - d;
		}
		
		// Print the modified character
		printf("%c", rr);
	}
	
	// Print a newline at the end of the output
	printf("\n");
	
	return 0;
}

