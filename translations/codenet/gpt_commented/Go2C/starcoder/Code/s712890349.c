

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Block represents a contiguous segment of characters with a specific value and length.
typedef struct {
	char value; // The character value of the block
	int len;    // The length of the block
} Block;

// RunLength performs run-length encoding on the input string s and returns a slice of Block
Block* RunLength(char* s) {
	int n = strlen(s);
	if (n == 0) {
		return NULL; // Return empty slice if input string is empty
	}

	// Initialize the first block with the first character of the string
	Block* t = (Block*)malloc(sizeof(Block));
	t->value = s[0];
	t->len = 1;
	for (int i = 1; i < n; i++) {
		// If the current character matches the block's value, increase the length
		if (t->value == s[i]) {
			t->len++;
		} else {
			// Otherwise, append the current block to the result and start a new block
			Block* tmp = (Block*)malloc(sizeof(Block));
			tmp->value = t->value;
			tmp->len = t->len;
			t = tmp;
			t->value = s[i];
			t->len = 1;
		}
	}
	// Append the last block to the result
	Block* tmp = (Block*)malloc(sizeof(Block));
	tmp->value = t->value;
	tmp->len = t->len;
	Block* r = (Block*)malloc(sizeof(Block));
	r[0] = *tmp;
	free(tmp);
	free(t);
	return r; // Return the slice of blocks
}

// Max returns the maximum of two integers
int Max(int a, int b) {
	if (b > a) {
		return b; // Return b if it is greater than a
	}
	return a; // Otherwise, return a
}

int main() {
	// Read input values for N (length of the string) and K (maximum number of '0's allowed)
	int N, K, ans = 0;
	scanf("%d %d", &N, &K);

	// Read the input string S
	char* S = (char*)malloc(sizeof(char) * (N + 1));
	scanf("%s", S);

	// Generate run-length encoded blocks from the input string S
	Block* blocks = RunLength(S);

	// Initialize variables for the sliding window approach
	int sum = 0, zero = 0, l = 0;

	// Iterate through the blocks to find the maximum length of segments with at most K '0's
	for (int r = 0; r < N; r++) {
		sum += blocks[r].len; // Add the length of the current block to the sum

		// Count the number of '0' blocks encountered
		if (blocks[r].value == '0') {
			zero++;
		}

		// If the count of '0' blocks exceeds K, shrink the window from the left
		while (K < zero) {
			sum -= blocks[l].len; // Subtract the length of the leftmost block from the sum
			if (blocks[l].value == '0') {
				zero--; // Decrease the count of '0' blocks
			}
			l++; // Move the left pointer to the right
		}

		// Update the answer with the maximum sum found so far
		ans = Max(ans, sum);
	}

	// Print the maximum length of segments with at most K '0's
	printf("%d\n", ans);
	return 0;
}

Complexity Analysis

Time Complexity: O(N), where N is the length of the input string.

Space Complexity: O(N), the space used by the blocks slice.

*/
