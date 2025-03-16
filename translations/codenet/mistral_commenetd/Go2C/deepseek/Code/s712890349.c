#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom type 'Block'
typedef struct {
    char Value[2];
    int Len;
} Block;

// Function to get the run-length encoded blocks
Block* RunLength(char* s, int len) {
    if (len == 0) {
        Block* empty = (Block*)malloc(0);
        return empty;
    }

    // Initialize the first block with the first character and length one
    Block t = {.Value = s[0], .Len = 1};

    // Initialize a pointer to the result array
    Block* r = (Block*)malloc(len * sizeof(Block));
    int r_index = 0;

    // Loop through all the characters in the input string starting from the second character
    for (int i = 1; i < len; i++) {
        // If the current character is the same as the previous character, increment the length of the current block
        if (t.Value[0] == s[i]) {
            t.Len++;
        } else {
            // Add the previous block to the result array
            r[r_index++] = t;

            // Initialize a new block with the current character and length one
            t = (Block){.Value = s[i], .Len = 1};
        }
    }

    // Add the last block to the result array
    r[r_index++] = t;

    // Resize the result array to the actual number of blocks
    r = (Block*)realloc(r, r_index * sizeof(Block));

    // Return the result array
    return r;
}

// Function to find the maximum of two integers
int Max(int a, int b) {
    // If b is greater than a, return b, otherwise return a
    return b > a ? b : a;
}

// Main function starts the execution
int main() {
    // Initialize variables
    int N, K, ans = 0;

    // Read input values for N and K from the standard input
    scanf("%d %d", &N, &K);

    // Allocate a character array of size 1,000,000 for reading input
    char* S = (char*)malloc(1000000 * sizeof(char));
    fgets(S, 1000000, stdin); // Read the entire line including the newline character

    // Allocate a character array for reading the input string
    char buffer[1000000];
    fgets(buffer, 1000000, stdin);

    // Copy the input string to the allocated array
    strcpy(S, buffer);

    // Remove the newline character from the input string
    S[strcspn(S, "\n")] = 0;

    // Call the RunLength function to get the run-length encoded blocks
    Block* blocks = RunLength(S, strlen(S));

    // Initialize variables sum, zero and length l
    int sum = 0, zero = 0, l = 0;

    // Loop through all the blocks in the blocks array
    for (int r = 0; r < sizeof(blocks) / sizeof(blocks[0]); r++) {
        // Increment the sum by the length of the current block
        sum += blocks[r].Len;

        // If the current block's value is '0', increment the zero counter
        if (blocks[r].Value[0] == '0') {
            zero++;
        }

        // While the zero counter is greater than K, subtract the length of the previous block from the sum and decrement the zero counter
        while (K < zero) {
            sum -= blocks[l].Len;
            if (blocks[l].Value[0] == '0') {
                zero--;
            }
            l++;
        }

        // Update the answer with the maximum of the current answer and the sum
        ans = Max(ans, sum);
    }

    // Print the final answer
    printf("%d\n", ans);

    // Free the allocated memory for the blocks array
    free(blocks);

    // Free the allocated memory for the input string
    free(S);

    return 0;
}
