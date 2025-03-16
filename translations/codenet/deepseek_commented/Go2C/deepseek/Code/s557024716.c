#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 1LL << 60
#define INF_INT32 1 << 30
#define NIL -1

#define WHITE 0
#define GRAY 1
#define BLACK 2

void init() {
    // Initialize input and output
}

void main() {
    int a, b, c, k;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &k);

    // Generate all possible patterns of length k where each element is one of 0, 1, 2, or 3.
    int patterns[4] = {0, 1, 2, 3};
    int pattern[k];
    generatePatterns(pattern, patterns, 0, k);

    // Iterate through each pattern to check the condition.
    for (int i = 0; i < pow(4, k); i++) {
        int r = a, g = b, _ = c; // Initialize r, g, and b with a, b, and c respectively.
        for (int j = 0; j < k; j++) {
            if (pattern[j] == 0) {
                continue; // If the operation is 0, do nothing.
            } else if (pattern[j] == 1) {
                r *= 2; // Double the value of r.
            } else if (pattern[j] == 2) {
                g *= 2; // Double the value of g.
            } else if (pattern[j] == 3) {
                _ *= 2; // Double the value of c.
            }
        }

        // Check if the condition b > a and c > b is met.
        if (g > r && _ > g) {
            printf("Yes\n"); // Print "Yes" if the condition is met.
            return;
        }
    }
    printf("No\n"); // Print "No" if no pattern meets the condition.
}

// Recursive function to generate all patterns of length k.
void generatePatterns(int pattern[], int patterns[], int depth, int k) {
    if (depth == k) {
        // Save the generated pattern
        return;
    }

    for (int i = 0; i < 4; i++) {
        pattern[depth] = patterns[i];
        generatePatterns(pattern, patterns, depth + 1, k);
    }
}
