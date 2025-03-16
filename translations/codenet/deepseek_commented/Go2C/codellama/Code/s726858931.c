
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initializes the scanner to read from standard input efficiently.
void scanInit() {
	const int cap = 1000 * 1024;
	char *buf = (char *)malloc(cap * sizeof(char));
	setvbuf(stdin, buf, _IOFBF, cap);
	return;
}

// Reads an integer from the input.
int nextInt() {
	char *str;
	int i, e;
	scanf("%ms", &str);
	i = atoi(str);
	free(str);
	if (e != 0) {
		printf("Error: %s\n", strerror(e));
		exit(1);
	}
	return i;
}

// Reads a string from the input.
char *nextStr() {
	char *str;
	scanf("%ms", &str);
	return str;
}

// Main function that executes the program logic.
int main() {
	scanInit();

	// Read the input string.
	char *s = nextStr();

	// Initialize the character to check against the string.
	char c = 'a';

	// Iterate through the alphabet to find the first missing character.
	for (int j = 0; j < 26; j++) {
		int found = 0;
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == c) {
				found = 1;
				break;
			}
		}
		if (found == 0) {
			printf("%c\n", c);
			return 0;
		}
		c++;
	}

	// If no missing character is found, print "None".
	printf("None\n");
	return 0;
}

