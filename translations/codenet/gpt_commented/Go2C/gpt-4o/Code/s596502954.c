#include <stdio.h>

int main() {
    int a, b, c; // Declare three integers

    // Read three integers from input
    scanf("%d %d %d", &a, &b, &c);

    // Check if the sum of the first two integers is greater than or equal to the third
    if (a + b >= c) {
        printf("Yes\n"); // Print "Yes" if the condition is true
    } else {
        printf("No\n"); // Print "No" otherwise
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
