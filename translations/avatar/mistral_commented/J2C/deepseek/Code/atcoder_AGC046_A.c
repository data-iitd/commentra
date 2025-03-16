#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer input
int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Main function starts here
int main() {

    // Reading the first integer input
    int x = readInt();

    // Initializing count variable to 0
    int count = 0;

    // Initializing temporary variable tmp with the value of x
    int tmp = x;

    // Setting x to 0
    x = 0;

    // Starting a while loop that runs until x is equal to 360
    while (x != 360) {

        // Adding the value of tmp to x
        x = x + tmp;

        // If x is greater than 360, then subtract 360 from it
        if (x > 360) {
            x = x - 360;
        }

        // Incrementing the count variable
        count++;
    }

    // Printing the value of count to the console
    printf("%d\n", count);

    return 0;
}
