#include <stdio.h>

int main() {
    int x, y, a, b;
    int count = 0;

    // Read four integers from the user
    scanf("%d %d %d %d", &x, &y, &a, &b);

    // First nested loop to iterate through the range [a, x]
    for (int i = a; i <= x; i++) {
        // Second nested loop to iterate through the range [b, y]
        for (int j = b; j <= y; ++j) {
            // Skip the iteration if i is less than or equal to j
            if (i <= j) continue;

            // Increment the count for each valid pair (i, j)
            count++;
        }
    }

    // Output the total count of valid pairs
    printf("%d\n", count);

    // Second set of nested loops to print the valid pairs
    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; ++j) {
            // Skip the iteration if i is less than or equal to j
            if (i <= j) continue;

            // Print the valid pair (i, j)
            printf("%d %d\n", i, j);
        }
    }

    return 0;
}
