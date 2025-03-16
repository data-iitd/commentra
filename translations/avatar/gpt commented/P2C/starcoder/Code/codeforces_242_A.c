#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read input values for x, y, a, and b and convert them to integers
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);

    // Initialize an empty list to store valid game pairs
    int games[x - a + 1][y - b + 1];

    // Iterate over the range from a to x (inclusive)
    for (int i = a; i <= x; i++) {
        // Skip the iteration if i is less than or equal to b
        if (i <= b) {
            continue;
        } else {
            // Iterate over the range from b to y (inclusive)
            for (int j = b; j <= y; j++) {
                // Check if the current i is greater than j
                if (i > j) {
                    // If the condition is met, append the pair (i, j) to the games list
                    games[i - a][j - b] = 1;
                }
            }
        }
    }

    // Print the total number of valid game pairs found
    printf("%d\n", x - a + 1);

    // Print each valid game pair
    for (int i = 0; i < x - a + 1; i++) {
        for (int j = 0; j < y - b + 1; j++) {
            if (games[i][j] == 1) {
                printf("%d %d\n", i + a, j + b);
            }
        }
    }

    return 0;
}
