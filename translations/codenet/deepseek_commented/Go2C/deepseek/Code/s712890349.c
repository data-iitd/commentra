#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Block represents a run-length encoded block of characters
typedef struct {
    char *Value;
    int Len;
} Block;

// RunLength performs run-length encoding on the input string
Block* RunLength(const char *s, int *blockCount) {
    Block *r = (Block *)malloc(sizeof(Block) * strlen(s));
    if (strlen(s) == 0) {
        *blockCount = 0;
        return r;
    }
    int count = 0;
    Block t = {.Value = (char *)malloc(2), .Len = 1};
    t.Value[0] = s[0];
    t.Value[1] = '\0';
    for (int i = 1; i < strlen(s); i++) {
        if (strcmp(t.Value, &s[i]) == 0) {
            t.Len++;
        } else {
            r[count++] = t;
            t.Value = (char *)malloc(2);
            t.Value[0] = s[i];
            t.Value[1] = '\0';
            t.Len = 1;
        }
    }
    r[count++] = t;
    *blockCount = count;
    return r;
}

// Max returns the maximum of two integers
int Max(int a, int b) {
    return b > a ? b : a;
}

int main() {
    int N, K, ans = 0;
    scanf("%d %d", &N, &K);
    char S[1000001];
    scanf("%s", S);

    // Apply Run Length Encoding to the input string S
    int blockCount;
    Block *blocks = RunLength(S, &blockCount);

    // Initialize variables for the sliding window approach
    int sum = 0, zero = 0, l = 0;
    for (int r = 0; r < blockCount; r++) {
        sum += blocks[r].Len;
        if (strcmp(blocks[r].Value, "0") == 0) {
            zero++;
        }
        // Adjust the window size if the number of '0' blocks exceeds K
        while (K < zero) {
            sum -= blocks[l].Len;
            if (strcmp(blocks[l].Value, "0") == 0) {
                zero--;
            }
            l++;
        }
        ans = Max(ans, sum);
    }
    printf("%d\n", ans);

    // Free allocated memory
    for (int i = 0; i < blockCount; i++) {
        free(blocks[i].Value);
    }
    free(blocks);

    return 0;
}

