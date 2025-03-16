#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Block represents a run-length encoded block of characters
typedef struct {
    char *Value;
    int Len;
} Block;

// Function to perform run-length encoding on the input string
Block* RunLength(const char *s, int *size) {
    int len = strlen(s);
    if (len == 0) {
        *size = 0;
        return NULL; // Return NULL if the input string is empty
    }

    Block *r = malloc(len * sizeof(Block)); // Allocate memory for blocks
    int count = 0;
    r[count].Value = malloc(2 * sizeof(char)); // Allocate memory for the first block
    r[count].Value[0] = s[0];
    r[count].Value[1] = '\0';
    r[count].Len = 1;

    for (int i = 1; i < len; i++) {
        if (s[i] == s[i - 1]) {
            r[count].Len++; // Increment the length of the current block if the character is the same
        } else {
            count++;
            r[count].Value = malloc(2 * sizeof(char)); // Allocate memory for the new block
            r[count].Value[0] = s[i];
            r[count].Value[1] = '\0';
            r[count].Len = 1; // Initialize a new block for the new character
        }
    }
<<<<<<< HEAD
    count++; // Increment count for the last block
    *size = count; // Set the size of the blocks array
=======
    *size = count + 1; // Set the size of the blocks array
>>>>>>> 98c87cb78a (data updated)
    return r; // Return the array of blocks
}

// Function to return the maximum of two integers
int Max(int a, int b) {
    return (b > a) ? b : a;
}

int main() {
    int N, K, ans = 0; // Declare variables for the number of characters, maximum allowed changes, and the answer
    scanf("%d %d", &N, &K); // Read the number of characters and the maximum allowed changes from the standard input
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
    char *S = malloc((N + 1) * sizeof(char)); // Allocate memory for the input string
    scanf("%s", S); // Read the input string from the standard input

    // Apply Run Length Encoding to the input string S
    int blockSize;
    Block *blocks = RunLength(S, &blockSize);

    // Initialize variables for the sliding window approach
    int sum = 0, zero = 0, l = 0;
    for (int r = 0; r < blockSize; r++) {
        sum += blocks[r].Len; // Add the length of the current block to the sum
        if (blocks[r].Value[0] == '0') {
            zero++; // Increment the count of '0' blocks
        }
        // Adjust the window size if the number of '0' blocks exceeds K
        while (zero > K) {
            sum -= blocks[l].Len; // Subtract the length of the block at the left of the window
            if (blocks[l].Value[0] == '0') {
                zero--; // Decrement the count of '0' blocks
            }
            l++; // Move the left pointer to the right
        }
        ans = Max(ans, sum); // Update the answer if the current window sum is greater
    }

    printf("%d\n", ans); // Print the final answer

    // Free allocated memory
    for (int i = 0; i < blockSize; i++) {
        free(blocks[i].Value); // Free each block's value
    }
    free(blocks); // Free the blocks array
    free(S); // Free the input string

    return 0;
}

// <END-OF-CODE>
