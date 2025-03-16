
#include <stdio.h> // Include the standard input and output library
#include <string.h> // Include the string manipulation library
#include <math.h> // Include the mathematical functions library

int main() {
    int a, b, c, d, e, k; // Declare and initialize six integer variables

    // Read the values of these variables from the standard input using scanf
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &k);

    // Perform a simple condition check using the relational operator <=
    if (e - a <= k) {
        printf("Yay!\n"); // If the condition is true, print "Yay!" to the standard output
    } else {
        printf(":(\n"); // If the condition is false, print ":" and a sad face "(" to the standard output
    }

    return 0; // Indicate that the program has finished running successfully
}

