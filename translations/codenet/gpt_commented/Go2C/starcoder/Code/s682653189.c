


#include <stdio.h>
#include <stdlib.h>

int main() {
	// Declare a variable to hold the input string
	char *s;
	
	// Read a string input from the user
	scanf("%s", &s);
	
	// Loop through each character in the string
	for (int i = 0; i < strlen(s); i++) {
		// Print 'x' for each character in the input string
		printf("x");
	}
	
	// Print a newline after printing all 'x's
	printf("\n");
}

