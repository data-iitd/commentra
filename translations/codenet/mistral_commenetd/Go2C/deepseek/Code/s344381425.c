#include <stdio.h>

int main() {
    int a, b, c;

    // Read three integers from the standard input
    scanf("%d %d %d", &a, &b, &c);

    // Check if the condition "a < b && b < c" is true using an if statement
    if (a < b && b < c) {
        // If the condition is true, print "Yes" to the standard output
        printf("Yes\n");
    } else {
        // If the condition is false, print "No" to the standard output
        printf("No\n");
    }

    // Return from the main function
    return 0;
}

