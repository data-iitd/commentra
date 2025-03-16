#include <stdio.h>
#include <ctype.h>

int main() {
	char s[1000];
	fgets(s, sizeof(s), stdin);

	// Define the difference between lowercase and uppercase ASCII values
	int d = 'a' - 'A';

	// Iterate over each character in the input string
	for (int i = 0; s[i] != '\0'; i++) {
		char r = s[i];
		// Check if the character is an uppercase letter
		if (isupper(r)) {
			// Convert uppercase to lowercase
			r = tolower(r);
		} else if (islower(r)) {
			// Convert lowercase to uppercase
			r = toupper(r);
		}
		// Print the converted character
		printf("%c", r);
	}
	printf("\n");

	return 0;
}
