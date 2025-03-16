// Importing necessary libraries
#include <stdio.h>

int main() {
    // Declaring variables
    int x, a, b;

    // Reading input values from standard input
    scanf("%d %d %d", &x, &a, &b);

    // Logic block to check if b is less than or equal to a
    if (b - a <= 0) {
        // Base case: If b is less than or equal to a
        printf("delicious\n");
    } else if (b - a <= x) {
        // Next case: If b is greater than a but less than or equal to x
        printf("safe\n");
    } else {
        // Default case: If none of the above conditions are met
        printf("dangerous\n");
    }

    return 0;
}

// <END-OF-CODE>
