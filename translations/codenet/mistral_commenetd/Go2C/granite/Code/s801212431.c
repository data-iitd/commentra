

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define initialBufSize 10000 // Initial buffer size
#define maxBufSize 10000000 // Maximum buffer size

// Function to read next token as a string
char* next() {
	static char buf[maxBufSize];
	scanf("%s", buf); // Read next token
	return buf; // Return token as string
}

// Function to find minimum of two integers
int min(int x, int y) {
	// If x is greater than y, return y
	if (x > y) {
		return y;
	} else {
		// Otherwise, return x
		return x;
	}
}

int main() {
	// Read input string S
	char* S = next();

	// Initialize variables l0 and l1 to store count of '0' and '1' respectively
	int l0 = 0, l1 = 0;

	// Iterate through each character in string S
	for (int i = 0; i < strlen(S); i++) {
		// If current character is '0', increment l0
		if (S[i] == '0') {
			l0++;
		} else {
			// Otherwise, increment l1
			l1++;
		}
	}

	// Print result which is twice the minimum of l0 and l1
	printf("%d\n", 2 * min(l0, l1)); // Print result

	return 0;
}
