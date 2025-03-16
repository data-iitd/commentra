#include <stdio.h>
#include <stdlib.h>

int main() {
	char *s = malloc(100 * sizeof(char));
	scanf("%s", s);

	// Define the difference between lowercase and uppercase ASCII values
	int d = 'a' - 'A';

	// Iterate over each character in the input string
	for (int i = 0; s[i] != '\0'; i++) {
		char r = s[i];
		// Check if the character is an uppercase letter
		if ('A' <= r && r <= 'Z') {
			// Convert uppercase to lowercase
			r = r + d;
		} else if ('a' <= r && r <= 'z') {
			// Convert lowercase to uppercase
			r = r - d;
		}
		// Print the converted character
		printf("%c", r);
	}
	printf("\n");
	return 0;
}
