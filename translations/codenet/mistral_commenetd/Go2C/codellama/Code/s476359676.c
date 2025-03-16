
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a scanner for reading input from stdin
char *scanner;

void init() {
	scanner = (char *)malloc(1000000001 * 3);
	scanf("%s", scanner);
}

char *nextStr() {
	char *token = strtok(scanner, " ");
	scanner = NULL;
	return token;
}

int nextInt() {
	char *token = nextStr();
	int i = atoi(token);
	return i;
}

// Main function to read input and process it
int main() {
	// Read the number of test cases
	int n = nextInt();

	// Initialize variables for processing the input
	int ans = 0;
	int aPrev = 0;

	// Process each test case
	for (int i = 0; i < n; i++) {
		// Read the next integer as 'a'
		int a = nextInt();

		// Check if 'a' is valid based on the conditions in the problem statement
		switch (a) {
		case a > i || a > aPrev + 1: // 'a' is not valid, print -1 and exit
			printf("%d\n", -1);
			return 0;
		case a == aPrev + 1: // Increment the answer if 'a' is consecutive with the previous number
			ans++;
		default: // Add 'a' to the answer if it's not consecutive but greater than the previous number
			ans += a;
		}

		// Update the previous number
		aPrev = a;
	}

	// Print the final answer
	printf("%d\n", ans);

	// End of code
	return 0;
}

