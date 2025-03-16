
#include <stdio.h>

int main() {
    int a, b, c, k;
    scanf("%d %d %d %d", &a, &b, &c, &k);

    // Generate all possible patterns of length k from the given array [0, 1, 2, 3]
    int patterns[4][k];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < k; j++) {
            patterns[i][j] = i;
        }
    }

    // Check each generated pattern
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 0) {
                continue;
            } else if (patterns[i][j] == 1) {
                a *= 2;
            } else if (patterns[i][j] == 2) {
                b *= 2;
            } else if (patterns[i][j] == 3) {
                c *= 2;
            }
        }

        // Check if the result satisfies the condition g > r and b > g
        if (b > a && c > b) {
            printf("Yes\n");
            return 0;
        }
    }

    // If all patterns are checked and no satisfying pattern is found, print "No"
    printf("No\n");

    return 0;
}
