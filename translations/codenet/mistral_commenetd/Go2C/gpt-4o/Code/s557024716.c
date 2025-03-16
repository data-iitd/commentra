#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define INF_INT64 9223372036854775807
#define INF_INT32 2147483647

int a, b, c, k;

// Function to generate all patterns of length k from the given array
void duplicatePatterns(int *elems, int elemsSize, int k, int **result, int *returnSize) {
    int maxPatterns = 1;
    for (int i = 0; i < k; i++) {
        maxPatterns *= elemsSize;
    }
    
    *result = (int *)malloc(maxPatterns * sizeof(int) * k);
    *returnSize = 0;

    for (int i = 0; i < maxPatterns; i++) {
        int *pattern = (int *)malloc(k * sizeof(int));
        for (int j = 0; j < k; j++) {
            pattern[j] = elems[(i / (maxPatterns / elemsSize)) % elemsSize];
            maxPatterns /= elemsSize;
        }
        for (int j = 0; j < k; j++) {
            (*result)[(*returnSize) * k + j] = pattern[j];
        }
        (*returnSize)++;
        free(pattern);
        maxPatterns = 1;
        for (int j = 0; j < k; j++) {
            maxPatterns *= elemsSize;
        }
    }
}

int main() {
    // Read input values
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &k);

    // Generate all possible patterns of length k from the given array [0, 1, 2, 3]
    int elems[] = {0, 1, 2, 3};
    int *patterns;
    int patternsSize;
    duplicatePatterns(elems, 4, k, &patterns, &patternsSize);

    // Check each generated pattern
    for (int i = 0; i < patternsSize; i++) {
        int r = a, g = b, b_val = c; // Use b_val to avoid conflict with the variable name b
        for (int j = 0; j < k; j++) {
            if (patterns[i * k + j] == 0) {
                continue;
            } else if (patterns[i * k + j] == 1) {
                r *= 2;
            } else if (patterns[i * k + j] == 2) {
                g *= 2;
            } else if (patterns[i * k + j] == 3) {
                b_val *= 2;
            }
        }

        // Check if the result satisfies the condition g > r and b > g
        if (g > r && b_val > g) {
            printf("Yes\n");
            free(patterns);
            return 0;
        }
    }

    // If all patterns are checked and no satisfying pattern is found, print "No"
    printf("No\n");
    free(patterns);
    return 0;
}

// <END-OF-CODE>
