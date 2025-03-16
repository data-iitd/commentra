#include <stdio.h>

int main(void) {
    // Declare four integer variables to hold input values
    int a, b, c, d;

    // Read four integers from user input
    scanf("%d%d%d%d", &a, &b, &c, &d);

    // Compare the sum of the first two integers (a and b) with the sum of the last two integers (c and d)
    if (a + b > c + d) {
        // If the sum of a and b is greater, print "Left"
        printf("Left\n");
    } else if (a + b < c + d) {
        // If the sum of a and b is less, print "Right"
        printf("Right\n");
    } else {
        // If both sums are equal, print "Balanced"
        printf("Balanced\n");
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}
