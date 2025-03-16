#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Block represents a contiguous segment of characters with a specific value and length.
typedef struct {
	char *value; // The character value of the block
	int len; // The length of the block
} Block;

int main() {
	// Read input values for N (length of the string) and K (maximum number of '0's allowed)
	int N, K, ans;
	scanf("%d %d", &N, &K);

	// Read the input string S
	char *S = (char *)malloc(N * sizeof(char));
	fgets(S, N, stdin);

	// Generate run-length encoded blocks from the input string S
	Block *blocks = RunLength(S);

	// Initialize variables for the sliding window approach
	int sum, zero, l;

	// Iterate through the blocks to find the maximum length of segments with at most K '0's
	for (int r = 0; r < N; r++) {
		sum += blocks[r].len; // Add the length of the current block to the sum

		// Count the number of '0' blocks encountered
		if (strcmp(blocks[r].value, "0") == 0) {
			zero++;
		}

		// If the count of '0' blocks exceeds K, shrink the window from the left
		while (K < zero) {
			sum -= blocks[l].len; // Subtract the length of the leftmost block from the sum
			if (strcmp(blocks[l].value, "0") == 0) {
				zero--; // Decrease the count of '0' blocks
			}
			l++; // Move the left pointer to the right
		}

		// Update the answer with the maximum sum found so far
		ans = (ans > sum) ? ans : sum;
	}

	// Print the maximum length of segments with at most K '0's
	printf("%d\n", ans);

	// Free the memory allocated for the input string S
	free(S);
	// Free the memory allocated for the blocks
	free(blocks);

	return 0;
}

// RunLength performs run-length encoding on the input string s and returns a slice of Block
Block *RunLength(char *s) {
	int N = strlen(s);
	Block *r = (Block *)malloc(N * sizeof(Block));
	if (N == 0) {
		return r; // Return empty slice if input string is empty
	}

	// Initialize the first block with the first character of the string
	Block t = {.value = (char *)malloc(2 * sizeof(char)), .len = 1};
	t.value[0] = s[0];
	t.value[1] = '\0';
	for (int i = 1; i < N; i++) {
		// If the current character matches the block's value, increase the length
		if (strcmp(t.value, &s[i]) == 0) {
			t.len++;
		} else {
			// Otherwise, append the current block to the result and start a new block
			r[i - 1] = t;
			t = (Block){.value = (char *)malloc(2 * sizeof(char)), .len = 1};
			t.value[0] = s[i];
			t.value[1] = '\0';
		}
	}
	// Append the last block to the result
	r[N - 1] = t;
	return r; // Return the slice of blocks
}

// Max returns the maximum of two integers
int Max(int a, int b) {
	if (b > a) {
		return b; // Return b if it is greater than a
	}
	return a; // Otherwise, return a
}

