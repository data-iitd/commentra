#include <stdio.h>

int main() {
    int a, b, c = 0; // Initialize variables
    scanf("%d %d", &a, &b); // Read first and second integer input

    if (a == 1 && b == 1) { // Check if both a and b are 1
        printf("0\n"); // Print 0 if true
    } else {
        while (a >= 1 || b >= 1) { // Continue until a or b is less than or equal to 0
            if (a >= b) { // If a is greater than or equal to b
                b++; // Increment b
                a -= 2; // Decrement a by 2
            } else { // If b is greater than a
                a++; // Increment a
                b -= 2; // Decrement b by 2
            }
            if (a <= 0 || b <= 0) { // Check if either a or b is less than or equal to 0
                c++; // Increment counter and break the loop
                break;
            }
            c++; // Increment counter in each iteration
        }
        printf("%d\n", c); // Print the final value of counter
    }

    return 0; // Return success
}

// <END-OF-CODE>
