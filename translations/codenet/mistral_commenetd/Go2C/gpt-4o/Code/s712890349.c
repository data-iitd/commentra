// Importing required libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom type 'Block'
typedef struct {
    char Value;
    int Len;
} Block;

// Function to find the maximum of two integers
int Max(int a, int b) {
    return (b > a) ? b : a;
}

// Function to get the run-length encoded blocks
Block* RunLength(const char* s, int* blockCount) {
    // If the length of the input string is zero, return NULL
    if (strlen(s) == 0) {
        *blockCount = 0;
        return NULL;
    }

    // Allocate memory for blocks
    Block* r = (Block*)malloc(strlen(s) * sizeof(Block));
    int count = 0;

    // Initialize the first block with the first character and length one
    Block t = {s[0], 1};

    // Loop through all the characters in the input string starting from the second character
    for (int i = 1; s[i] != '\0'; i++) {
        // If the current character is the same as the previous character, increment the length of the current block
        if (t.Value == s[i]) {
            t.Len++;
        } else {
            // Add the previous block to the result array
            r[count++] = t;

            // Initialize a new block with the current character and length one
            t.Value = s[i];
            t.Len = 1;
        }
    }

    // Add the last block to the result array
    r[count++] = t;

    *blockCount = count; // Set the block count
    return r; // Return the result array
}

// Main function starts the execution
int main() {
    // Initialize variables
    int N, K, ans = 0;

    // Read input values for N and K from the standard input
    scanf("%d %d", &N, &K);

    // Allocate memory for the input string
    char* S = (char*)malloc(1000000 * sizeof(char));

    // Read the input string S from the standard input
    scanf("%s", S);

    // Call the RunLength function to get the run-length encoded blocks
    int blockCount;
    Block* blocks = RunLength(S, &blockCount);

    // Initialize variables sum, zero and length l
    int sum = 0, zero = 0, l = 0;

    // Loop through all the blocks in the blocks array
    for (int r = 0; r < blockCount; r++) {
        // Increment the sum by the length of the current block
        sum += blocks[r].Len;

        // If the current block's value is '0', increment the zero counter
        if (blocks[r].Value == '0') {
            zero++;
        }

        // While the zero counter is greater than K, subtract the length of the previous block from the sum and decrement the zero counter
        while (zero > K) {
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
    printf("%d\n", ans);

    // Free allocated memory
    free(S);
    free(blocks);

    return 0;
}

// <END-OF-CODE>
