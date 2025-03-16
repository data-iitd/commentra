// Importing required packages
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom type 'Block'
typedef struct {
	char Value;
	int Len;
} Block;

// Main function starts the execution
int main() {
	// Initialize variables
	int N, K, ans, sum, zero, l;

	// Read input values for N and K from the standard input
	scanf("%d %d", &N, &K);

	// Initialize a buffer scanner for reading input from the standard input
	char S[1000000];
	char *s = fgets(S, 1000000, stdin);

	// Initialize a pointer to the first character of the input string
	char *p = S;

	// Initialize a pointer to the first block
	Block *blocks = (Block *)malloc(sizeof(Block));

	// Initialize a pointer to the current block
	Block *t = blocks;

	// Loop through all the characters in the input string
	while (*p != '\0') {
		// If the current character is the same as the previous character, increment the length of the current block
		if (t->Value == *p) {
			t->Len++;
		} else {
			// If the current character is not the same as the previous character, add the previous block to the result slice
			t = (Block *)realloc(blocks, (t - blocks + 2) * sizeof(Block));

			// Initialize a new block with the current character and length one
			t[1].Value = *p;
			t[1].Len = 1;

			// Increment the pointer to the current block
			t++;
		}

		// Increment the pointer to the next character
		p++;
	}

	// Add the last block to the result slice
	t = (Block *)realloc(blocks, (t - blocks + 2) * sizeof(Block));
	t[1].Value = '\0';
	t[1].Len = 0;
	t++;

	// Initialize variables sum, zero and length l
	sum = 0;
	zero = 0;
	l = 0;

	// Loop through all the blocks in the blocks slice
	for (Block *r = blocks; r < t; r++) {
		// Increment the sum by the length of the current block
		sum += r->Len;

		// If the current block's value is '0', increment the zero counter
		if (r->Value == '0') {
			zero++;
		}

		// While the zero counter is greater than K, subtract the length of the previous block from the sum and decrement the zero counter
		while (K < zero) {
			sum -= (r - l)->Len;
			if ((r - l)->Value == '0') {
				zero--;
			}
			l++;
		}

		// Update the answer with the maximum of the current answer and the sum
		ans = ans > sum ? ans : sum;
	}

	// Print the final answer
	printf("%d\n", ans);

	// Free the memory allocated for the blocks slice
	free(blocks);

	// End of the code
	return 0;
}

// End of the code


