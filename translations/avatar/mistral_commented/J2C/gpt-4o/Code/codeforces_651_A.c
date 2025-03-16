#include <stdio.h>  // Importing standard input and output library
#include <stdlib.h> // Importing standard library for exit function

// Main function is the entry point of the C application
int main() {
    // Declaring variables for input
    int a, b, c = 0;

    // Reading two integers 'a' and 'b' from the standard input
    scanf("%d %d", &a, &b);

    // Checking if both 'a' and 'b' are equal to 1. If yes, then print 0 and exit
    if (a == 1 && b == 1) {
        printf("0\n");  // Printing 0 as the output
        exit(0);  // Exiting the main function
    } else {
        // Performing the loop until either 'a' or 'b' becomes 0
        while (a >= 1 || b >= 1) {
            // If 'a' is greater than or equal to 'b', then decrement 'b' and increment 'a' by 2
            if (a >= b) {
                b++;
                a -= 2;
            } 
            // If 'a' is less than 'b', then increment 'a' and decrement 'b' by 2
            else {
                a++;
                b--;
            }

            // Checking if either 'a' or 'b' has become 0. If yes, then increment 'c' and break the loop
            if (a <= 0 || b <= 0) {
                c++;
                break;
            }

            // Incrementing 'c' for each iteration of the loop
            c++;
        }

        // Printing the final result 'c' as the output
        printf("%d\n", c);
    }

    return 0; // Returning 0 to indicate successful execution
}

// Static method for swapping two integers (not used in this code)
// void swap(int a, int b) {
//     int t = b;
//     b = a;
//     a = t;
// }

// Static method for debugging purposes (not used in this code)
// void debug(Object... obj) {
//     // Printing the debug information
// }

// Helper method for exiting the main function (not needed in C)
// void exitMainFunction() {
//     exit(0);
// }

