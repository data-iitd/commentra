// Importing necessary libraries for input/output operations
#include <stdio.h>

int main() {
    // Declaring variables to hold the input values
    int h, a;

    // Reading a single line of input from the console
    scanf("%d %d", &h, &a);

    // Initializing a variable 'num' to keep track of the number of steps
    int num = 0;

    // Using a while loop to simulate the given condition
    while (h > 0) {
        // Subtracting 'a' from 'h' in each iteration
        h -= a;

        // Incrementing the 'num' variable after each successful subtraction
        num++;
    }

    // Printing the final result 'num' to the console
    printf("%d\n", num);

    return 0;
}

// <END-OF-CODE>
