
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Block represents a run-length encoded block of characters
typedef struct {
	char *value;
	int len;
} Block;

int main() {
	int N, K, ans, sum, zero, l, r; // Declare variables for the number of characters, maximum allowed changes, and the answer
	scanf("%d %d", &N, &K); // Read the number of characters and the maximum allowed changes from the standard input
	char *S = (char *)malloc(N * sizeof(char)); // Allocate memory for the input string
	scanf("%s", S); // Read the input string from the standard input

	// Apply Run Length Encoding to the input string S
	Block *blocks = RunLength(S);

	// Initialize variables for the sliding window approach
	sum = zero = l = 0;
	for (r = 0; r < N; r++) {
		sum += blocks[r].len; // Add the length of the current block to the sum
		if (strcmp(blocks[r].value, "0") == 0) {
			zero++; // Increment the count of '0' blocks
		}
		// Adjust the window size if the number of '0' blocks exceeds K
		while (K < zero) {
			sum -= blocks[l].len; // Subtract the length of the block at the left of the window
			if (strcmp(blocks[l].value, "0") == 0) {
				zero--; // Decrement the count of '0' blocks
			}
			l++; // Move the left pointer to the right
		}
		ans = (ans > sum) ? ans : sum; // Update the answer if the current window sum is greater
	}
	printf("%d\n", ans); // Print the final answer
	return 0;
}

// RunLength performs run-length encoding on the input string
Block *RunLength(char *s) {
	int i, j, len = strlen(s); // Declare variables for the length of the input string
	Block *r = (Block *)malloc(len * sizeof(Block)); // Allocate memory for the encoded blocks
	if (len == 0) {
		return r; // Return an empty slice if the input string is empty
	}
	Block t = {.value = (char *)malloc(2 * sizeof(char)), .len = 1}; // Initialize the first block
	for (i = 0, j = 1; j < len; i++, j++) {
		if (strcmp(t.value, &s[j]) == 0) {
			t.len++; // Increment the length of the current block if the character is the same
		} else {
			r[i] = t; // Append the current block to the result slice
			t = (Block){.value = (char *)malloc(2 * sizeof(char)), .len = 1}; // Initialize a new block for the new character
			t.value[0] = s[j]; // Set the value of the new block
		}
	}
	r[i] = t; // Append the last block to the result slice
	return r;
}

// Max returns the maximum of two integers
int Max(int a, int b) {
	if (b > a) {
		return b;
	}
	return a;
}

