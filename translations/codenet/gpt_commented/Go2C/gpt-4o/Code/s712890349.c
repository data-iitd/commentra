#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Block represents a contiguous segment of characters with a specific value and length.
typedef struct {
    char *Value; // The character value of the block
    int Len;     // The length of the block
} Block;

// Function to perform run-length encoding on the input string s and return an array of Block
Block* RunLength(const char *s, int *blockCount) {
    int len = strlen(s);
    if (len == 0) {
        *blockCount = 0;
        return NULL; // Return NULL if input string is empty
    }

    Block *blocks = malloc(len * sizeof(Block)); // Allocate memory for blocks
    *blockCount = 0; // Initialize block count

    // Initialize the first block with the first character of the string
    blocks[*blockCount].Value = malloc(2 * sizeof(char)); // Allocate memory for the character
    blocks[*blockCount].Value[0] = s[0];
    blocks[*blockCount].Value[1] = '\0'; // Null-terminate the string
    blocks[*blockCount].Len = 1;
<<<<<<< HEAD
    (*blockCount)++;

    for (int i = 1; i < len; i++) {
        // If the current character matches the block's value, increase the length
        if (s[i] == blocks[*blockCount - 1].Value[0]) {
            blocks[*blockCount - 1].Len++;
        } else {
            // Otherwise, append the current block to the result and start a new block
=======

    for (int i = 1; i < len; i++) {
        // If the current character matches the block's value, increase the length
        if (blocks[*blockCount].Value[0] == s[i]) {
            blocks[*blockCount].Len++;
        } else {
            // Otherwise, append the current block to the result and start a new block
            (*blockCount)++;
>>>>>>> 98c87cb78a (data updated)
            blocks[*blockCount].Value = malloc(2 * sizeof(char)); // Allocate memory for the new character
            blocks[*blockCount].Value[0] = s[i];
            blocks[*blockCount].Value[1] = '\0'; // Null-terminate the string
            blocks[*blockCount].Len = 1;
<<<<<<< HEAD
            (*blockCount)++;
        }
    }
=======
        }
    }
    (*blockCount)++; // Increment for the last block
>>>>>>> 98c87cb78a (data updated)
    return blocks; // Return the array of blocks
}

// Function to return the maximum of two integers
int Max(int a, int b) {
<<<<<<< HEAD
    return (b > a) ? b : a; // Return the maximum value
=======
    return (b > a) ? b : a; // Return the maximum
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    // Read input values for N (length of the string) and K (maximum number of '0's allowed)
    int N, K, ans = 0;
    scanf("%d %d", &N, &K);

    // Read the input string S
    char *S = malloc((N + 1) * sizeof(char)); // Allocate memory for the string
<<<<<<< HEAD
    scanf("%s", S); // Store the scanned text in S
=======
    scanf("%s", S); // Read the string
>>>>>>> 98c87cb78a (data updated)

    // Generate run-length encoded blocks from the input string S
    int blockCount;
    Block *blocks = RunLength(S, &blockCount);

    // Initialize variables for the sliding window approach
    int sum = 0, zero = 0, l = 0;

    // Iterate through the blocks to find the maximum length of segments with at most K '0's
    for (int r = 0; r < blockCount; r++) {
        sum += blocks[r].Len; // Add the length of the current block to the sum

        // Count the number of '0' blocks encountered
        if (blocks[r].Value[0] == '0') {
            zero++;
        }

        // If the count of '0' blocks exceeds K, shrink the window from the left
        while (zero > K) {
            sum -= blocks[l].Len; // Subtract the length of the leftmost block from the sum
            if (blocks[l].Value[0] == '0') {
                zero--; // Decrease the count of '0' blocks
            }
            l++; // Move the left pointer to the right
        }

        // Update the answer with the maximum sum found so far
        ans = Max(ans, sum);
    }

    // Print the maximum length of segments with at most K '0's
    printf("%d\n", ans);

    // Free allocated memory
    for (int i = 0; i < blockCount; i++) {
        free(blocks[i].Value); // Free each block's value
    }
    free(blocks); // Free the blocks array
    free(S); // Free the input string

    return 0;
}

// <END-OF-CODE>
