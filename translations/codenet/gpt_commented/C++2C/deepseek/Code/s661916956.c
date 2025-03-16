#include <stdio.h> // Include the stdio library for input and output
#include <stdlib.h> // Include the stdlib library for the swap function

int main() {
    int a, b, c; // Declare three integer variables to hold the input values
    scanf("%d %d %d", &a, &b, &c); // Read three integers from the user

    // Check if 'a' is greater than 'b', if so, swap their values
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Check if 'b' is greater than 'c', if so, swap their values
    if (b > c) {
        int temp = b;
        b = c;
        c = temp;
    }

    // Check again if 'a' is greater than 'b', if so, swap their values
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Output the sorted values of a, b, and c
    printf("%d %d %d\n", a, b, c);

    return 0; // Return 0 to indicate successful completion of the program
}
