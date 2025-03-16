#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define ALPHABET_NUM 26
#define INF_INT64 LLONG_MAX
#define INF_BIT60 (1LL << 60)
#define INF_INT32 INT_MAX
#define INF_BIT30 (1 << 30)
#define NIL -1

void generatePatterns(int *pattern, int *elems, int k, int index, int **results, int *resultCount);
<<<<<<< HEAD
void freePatterns(int **patterns, int count);
=======
int checkCondition(int r, int g, int b);
>>>>>>> 98c87cb78a (data updated)

int main() {
    int a, b, c, k;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &k);

    int elems[] = {0, 1, 2, 3};
    int **patterns = (int **)malloc(pow(4, k) * sizeof(int *));
    int resultCount = 0;

<<<<<<< HEAD
    generatePatterns((int *)malloc(k * sizeof(int)), elems, k, 0, patterns, &resultCount);

=======
    // Generate all possible patterns of length k
    int *pattern = (int *)malloc(k * sizeof(int));
    generatePatterns(pattern, elems, k, 0, patterns, &resultCount);

    // Iterate through each generated pattern
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < resultCount; i++) {
        int r = a, g = b, b_val = c; // Initialize color values for each pattern
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue; // Skip if the pattern element is 0
            } else if (patterns[i][j] == 1) {
                r *= 2; // Double the red value
            } else if (patterns[i][j] == 2) {
                g *= 2; // Double the green value
            } else if (patterns[i][j] == 3) {
                b_val *= 2; // Double the blue value
            }
        }

        // Check if the modified values satisfy the condition
<<<<<<< HEAD
        if (g > r && b_val > g) {
            printf("Yes\n"); // Print "Yes" if the condition is met
            freePatterns(patterns, resultCount);
=======
        if (checkCondition(r, g, b_val)) {
            printf("Yes\n"); // Print "Yes" if the condition is met
>>>>>>> 98c87cb78a (data updated)
            return 0;
        }
    }
    printf("No\n"); // Print "No" if no pattern satisfies the condition
<<<<<<< HEAD
    freePatterns(patterns, resultCount);
    return 0;
}

// Function to generate all patterns of length k from the given elements.
=======

    // Free allocated memory
    for (int i = 0; i < resultCount; i++) {
        free(patterns[i]);
    }
    free(patterns);
    free(pattern);

    return 0;
}

// Function to generate all patterns of length k
>>>>>>> 98c87cb78a (data updated)
void generatePatterns(int *pattern, int *elems, int k, int index, int **results, int *resultCount) {
    if (index == k) {
        results[*resultCount] = (int *)malloc(k * sizeof(int));
        memcpy(results[*resultCount], pattern, k * sizeof(int));
        (*resultCount)++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        pattern[index] = elems[i];
        generatePatterns(pattern, elems, k, index + 1, results, resultCount);
    }
}

<<<<<<< HEAD
// Function to free allocated patterns
void freePatterns(int **patterns, int count) {
    for (int i = 0; i < count; i++) {
        free(patterns[i]);
    }
    free(patterns);
=======
// Function to check the condition
int checkCondition(int r, int g, int b) {
    return g > r && b > g;
>>>>>>> 98c87cb78a (data updated)
}

/* <END-OF-CODE> */
