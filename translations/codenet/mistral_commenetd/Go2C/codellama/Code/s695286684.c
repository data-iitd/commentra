// 2018-07-29T20:36:21+0800
#include <stdio.h>
#include <string.h>

// Define a variable `s` of type `char` to store the user input.
char s[100];

// Read a string input from the standard input and store it in the variable `s`.
int main() {
	printf("Enter a string: "); // Print a prompt message to the standard output.
	scanf("%s", s); // Read a string input from the standard input and store it in the variable `s`.

	// Replace all occurrences of the string "2017" in the string `s` with the string "2018".
	char *p = strstr(s, "2017");
	while (p != NULL) {
		strcpy(p, "2018");
		p = strstr(p + 4, "2017");
	}

	// Print the modified string to the standard output.
	printf("Modified string: %s\n", s);

	return 0;
}

// End of code.


