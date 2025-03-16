#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare two integers
    int a, b;
    // Declare a counter for the number of operations
    int c = 0;
    // Read two integers from input
    scanf("%d %d", &a, &b);
    // Check for the special case where both a and b are 1
    if (a == 1 && b == 1) {
        printf("0\n"); // Output 0 operations needed
    } else {
        // Loop until both a and b are non-positive
        while (a >= 1 || b >= 1) {
            // If a is greater than or equal to b, perform operation on a
            if (a >= b) {
                b++; // Increment b
                a -= 2; // Decrement a by 2
            } else {
                // If b is greater than a, perform operation on b
                a++; // Increment a
                b -= 2; // Decrement b by 2
            }
            // Check if either a or b has become non-positive
            if (a <= 0 || b <= 0) {
                c++; // Increment operation counter and break
                break; 
            }
            c++; // Increment operation counter
        }
        // Output the total number of operations performed
        printf("%d\n", c); 
    }
    return 0;
}

