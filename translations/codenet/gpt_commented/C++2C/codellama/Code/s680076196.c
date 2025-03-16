#include <stdio.h> // Include the standard input-output library

int main() {
    int a, b, c, d; // Declare four integer variables to hold input values

    // Read four integer values from standard input
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Calculate the product of the differences between the first two and the last two integers
    // This represents the area of a rectangle defined by the points (a, b) and (c, d)
    printf("%d\n", (a - c) * (b - d));

    return 0; // Return 0 to indicate successful completion of the program
}

