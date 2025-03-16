
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom type 'Block'
typedef struct {
	char Value;
	int Len;
} Block;

// Function to get the run-length encoded blocks
Block* RunLength(char* s) {
	// If the length of the input string is zero, return NULL
	if (strlen(s) == 0) {
		return NULL;
	}

	// Initialize the first block with the first character and length one
	Block* t = (Block*)malloc(sizeof(Block));
	t->Value = s[0];
	t->Len = 1;

	// Initialize an empty slice to store the blocks
	Block* r = NULL;

	// Loop through all the characters in the input string starting from the second character
	for (int i = 1; i < strlen(s); i++) {
		// If the current character is the same as the previous character, increment the length of the current block
		if (t->Value == s[i]) {
			t->Len++;
		} else {
			// Add the previous block to the result slice
			r = (Block*)realloc(r, sizeof(Block) * (1 + (r == NULL? 0 : (int)sizeof(Block) * (strlen(s) - 1))));
			r[strlen(s) - 1] = *t;

			// Initialize a new block with the current character and length one
			t = (Block*)malloc(sizeof(Block));
			t->Value = s[i];
			t->Len = 1;
		}
	}

	// Add the last block to the result slice
	r = (Block*)realloc(r, sizeof(Block) * (1 + (r == NULL? 0 : (int)sizeof(Block) * (strlen(s) - 1))));
	r[strlen(s) - 1] = *t;

	// Return the result slice
	return r;
}

// Function to find the maximum of two integers
int Max(int a, int b) {
	// If b is greater than a, return b, otherwise return a
	if (b > a) {
		return b;
	}
	return a;
}

// Main function starts the execution
int main() {
	// Initialize variables
	int N, K, ans = 0;

	// Read input values for N and K from the standard input
	scanf("%d %d", &N, &K);

	// Initialize a buffer scanner for reading input from the standard input
	char* S = (char*)malloc(1000000);
	scanf("%s", S);

	// Call the RunLength function to get the run-length encoded blocks
	Block* blocks = RunLength(S);

	// Initialize variables sum, zero and length l
	int sum = 0, zero = 0, l = 0;

	// Loop through all the blocks in the blocks slice
	for (int r = 0; r < strlen(S); r++) {
		// Increment the sum by the length of the current block
		sum += blocks[r].Len;

		// If the current block's value is '0', increment the zero counter
		if (blocks[r].Value == '0') {
			zero++;
		}

		// While the zero counter is greater than K, subtract the length of the previous block from the sum and decrement the zero counter
		while (K < zero) {
			sum -= blocks[l].Len;
			if (blocks[l].Value == '0') {
				zero--;
			}
			l++;
		}

		// Update the answer with the maximum of the current answer and the sum
		ans = Max(ans, sum);
	}

	// Print the final answer
	printf("%d", ans);

	// Free the memory allocated to the buffer scanner
	free(S);

	// Free the memory allocated to the blocks slice
	free(blocks);

	// Return from the main function
	return 0;
}

// End of the code

