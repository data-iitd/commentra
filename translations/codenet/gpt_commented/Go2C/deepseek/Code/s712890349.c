#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    char Value[2]; // The character value of the block
    int Len;       // The length of the block
} Block;

Block* RunLength(const char* s, int* len) {
    Block* r = (Block*)malloc(*len * sizeof(Block));
    if (*len == 0) {
        return r; // Return empty slice if input string is empty
    }

    // Initialize the first block with the first character of the string
    Block t = {.Value = {s[0]}, .Len = 1};
    int index = 0;
    for (int i = 1; i < *len; i++) {
        // If the current character matches the block's value, increase the length
        if (t.Value[0] == s[i]) {
            t.Len++;
        } else {
            // Otherwise, append the current block to the result and start a new block
            r[index++] = t;
            t = (Block){.Value = {s[i]}, .Len = 1};
        }
    }
    // Append the last block to the result
    r[index++] = t;
    *len = index; // Update the length of the result array
    return r; // Return the slice of blocks
}

int main() {
    int N, K, ans = 0;
    scanf("%d %d", &N, &K);

    // Read the input string S
    char S[1000001];
    scanf("%s", S);

    // Generate run-length encoded blocks from the input string S
    int len;
    Block* blocks = RunLength(S, &len);

    // Initialize variables for the sliding window approach
    int sum = 0, zero = 0, l = 0;

    // Iterate through the blocks to find the maximum length of segments with at most K '0's
    for (int r = 0; r < len; r++) {
        sum += blocks[r].Len; // Add the length of the current block to the sum

        // Count the number of '0' blocks encountered
        if (blocks[r].Value[0] == '0') {
            zero++;
        }

        // If the count of '0' blocks exceeds K, shrink the window from the left
        while (K < zero) {
            sum -= blocks[l].Len; // Subtract the length of the leftmost block from the sum
            if (blocks[l].Value[0] == '0') {
                zero--; // Decrease the count of '0' blocks
            }
            l++; // Move the left pointer to the right
        }

        // Update the answer with the maximum sum found so far
        ans = MAX(ans, sum);
    }

    // Print the maximum length of segments with at most K '0's
    printf("%d\n", ans);

    // Free the allocated memory for blocks
    free(blocks);
    return 0;
}
