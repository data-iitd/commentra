#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 1000000007

<<<<<<< HEAD
// Function to generate all patterns of length k
void generatePatterns(int *pattern, int *elems, int k, int index, int **results, int *resultCount) {
    if (index == k) {
        results[*resultCount] = (int *)malloc(k * sizeof(int));
        for (int i = 0; i < k; i++) {
            results[*resultCount][i] = pattern[i];
        }
        (*resultCount)++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        pattern[index] = elems[i];
        generatePatterns(pattern, elems, k, index + 1, results, resultCount);
    }
}

// Main function
int main() {
    int a, b, c, k;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &k);

    int elems[4] = {0, 1, 2, 3};
    int **patterns = (int **)malloc(100000 * sizeof(int *)); // Allocate memory for patterns
    int pattern[10]; // Maximum length of pattern
    int resultCount = 0;

    // Generate all possible patterns of length k
    generatePatterns(pattern, elems, k, 0, patterns, &resultCount);

    // Check each pattern
    for (int i = 0; i < resultCount; i++) {
        int r = a, g = b, c_temp = c; // Initialize r, g, and c_temp with a, b, and c respectively
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue; // If the operation is 0, do nothing
            } else if (patterns[i][j] == 1) {
                r *= 2; // Double the value of r
            } else if (patterns[i][j] == 2) {
                g *= 2; // Double the value of g
            } else if (patterns[i][j] == 3) {
                c_temp *= 2; // Double the value of c
            }
        }

        // Check if the condition g > r and c_temp > g is met
        if (g > r && c_temp > g) {
            printf("Yes\n"); // Print "Yes" if the condition is met
            for (int j = 0; j < resultCount; j++) {
                free(patterns[j]); // Free allocated memory
            }
            free(patterns);
            return 0;
        }
    }

    printf("No\n"); // Print "No" if no pattern meets the condition
    for (int j = 0; j < resultCount; j++) {
        free(patterns[j]); // Free allocated memory
    }
    free(patterns);
    return 0;
}

/* <END-OF-CODE> */
=======
// Function to read an integer from input
int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to generate all patterns of length k
void generatePatterns(int *pattern, int k, int index, int a, int b, int c) {
    if (index == k) {
        // Check the condition for the current pattern
        int r = a, g = b, cc = c;
        for (int i = 0; i < k; i++) {
            if (pattern[i] == 1) {
                r *= 2;
            } else if (pattern[i] == 2) {
                g *= 2;
            } else if (pattern[i] == 3) {
                cc *= 2;
            }
        }
        if (g > r && cc > g) {
            printf("Yes\n");
            exit(0); // Exit if the condition is met
        }
        return;
    }

    // Generate patterns by trying each operation
    for (int i = 0; i < 4; i++) {
        pattern[index] = i; // Set the current operation
        generatePatterns(pattern, k, index + 1, a, b, c); // Recur for the next index
    }
}

int main() {
    int a = readInt(); // Read a
    int b = readInt(); // Read b
    int c = readInt(); // Read c
    int k = readInt(); // Read k

    int *pattern = (int *)malloc(k * sizeof(int)); // Allocate memory for the pattern
    generatePatterns(pattern, k, 0, a, b, c); // Start generating patterns

    printf("No\n"); // If no pattern meets the condition
    free(pattern); // Free allocated memory
    return 0;
}

/<END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
