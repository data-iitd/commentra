#include <stdio.h>

int main() {
    // Declare variables to hold input values
    int x, y, a, b;

    // Read four integers from the console
    scanf("%d %d %d %d", &x, &y, &a, &b);

    // Initialize a counter variable
    int count = 0;

    // Find the number of pairs (i, j) that satisfy the condition i < j
    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; j++) {
            // If i is less than or equal to j, continue to the next iteration of the inner loop
            if (i <= j) continue;

            // Increment the counter if the condition is satisfied
            count++;
        }
    }

    // Print the result
    printf("%d\n", count);

    // Print all pairs (i, j) that satisfy the condition i < j
    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; j++) {
            // If i is less than or equal to j, print the pair
            if (i <= j) {
                printf("%d %d\n", i, j);
            }
        }
    }

    return 0; // Return success
}

// <END-OF-CODE>
