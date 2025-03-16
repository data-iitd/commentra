#include <iostream>

using namespace std;

int main(void) {
    // Variable declarations
    int a, b, n; // Input values and loop counters
    int sum; // To store the sum of the digits
    int i, j; // Loop counters

    // Infinite loop
    while (1) {
        // Read three integers from standard input
        if (scanf("%d %d %d", &a, &b, &n) == -1)
            break; // Break if input reading fails

        // Reduce 'a' to its remainder when divided by 'b'
        a -= a / b * b;

        // Initialize sum to zero
        sum = 0;

        // Outer loop runs 'n' times
        for (i = 1; i <= n; i++) {
            // Multiply 'a' by 10 to shift the decimal point
            a *= 10;

            // Inner loop iterates from 9 down to 0
            for (j = 9; j >= 0; j--) {
                // Find the largest digit 'j' such that 'b*j' is less than or equal to 'a'
                if (b * j <= a)
                    break;
            }

            // Subtract 'b*j' from 'a' and add 'j' to the sum
            a -= b * j;
            sum += j;
        }

        // Output the sum of the digits
        printf("%d\n", sum);
    }

    // Return 0 to indicate successful execution
    return 0;
}
