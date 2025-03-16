#include <stdio.h>

int main() {
    int x, y, a, b;
    int count = 0;

    // Read four integers from input
    scanf("%d %d %d %d", &x, &y, &a, &b);

    // Nested loops to iterate through possible pairs (i, j)
    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; j++) {
            if (i <= j) continue; // Skip pairs where i is not greater than j
            count++; // Increment counter for each valid pair
        }
    }

    // Print the total count of valid pairs
    printf("%d\n", count);

    // Print each valid pair
    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; j++) {
            if (i <= j) continue; // Skip pairs where i is not greater than j
            printf("%d %d\n", i, j); // Print each valid pair
        }
    }

    return 0;
}

