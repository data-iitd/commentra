#include <stdio.h>

int main() {
    int a, b, res;

    // Read the first integer input
    scanf("%d", &a);
    // Read the second integer input
    scanf("%d", &b);
    
    // Initialize result variable with the value of a
    res = a;

    // Enter a while loop that continues as long as a is greater than or equal to b
    while (a >= b) {
        res += (a / b); // Update result by adding the integer division of a by b
        a = (a / b) + (a % b); // Update a to be the sum of the integer division and remainder
    }

    // Print the final value of res
    printf("%d\n", res);

    return 0;
}

// <END-OF-CODE>
