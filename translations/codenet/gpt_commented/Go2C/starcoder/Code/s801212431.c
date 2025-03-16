

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to read the next word from input
char* next() {
	char* w = NULL;
	int c = EOF;
	int i = 0;
	while (isspace(c)) {
		c = getchar();
	}
	if (c!= EOF) {
		w = malloc(sizeof(char));
		w[i++] = c;
	}
	while ((c = getchar())!= EOF &&!isspace(c)) {
		w = realloc(w, i + 1);
		w[i++] = c;
	}
	w = realloc(w, i + 1);
	w[i] = '\0';
	return w;
}

// Function to return the minimum of two integers
int min(int x, int y) {
	if (x > y) {
		return y;
	} else {
		return x;
	}
}

// Main function where the program execution begins
int main() {
	char* S = next(); // Read the input string

	int l0 = 0, l1 = 0; // Initialize counters for '0's and '1's
	// Loop through each character in the input string
	for (int i = 0; i < strlen(S); i++) {
		if (S[i] == '0') {
			l0++; // Increment the counter for '0'
		} else {
			l1++; // Increment the counter for '1'
		}
	}
	// Print the result, which is twice the minimum count of '0's or '1's
	printf("%d\n", 2 * min(l0, l1));
	return 0;
}

