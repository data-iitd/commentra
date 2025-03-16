#include<stdio.h>

int main() {
    // Declare integer variables to hold input values and results
    int a, b, c, d, i, j;

    // Read four integers from user input
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Calculate the product of the first two integers
    i = a * b;

    // Calculate the product of the last two integers
    j = c * d;

    // Compare the two products and print the larger one
    if (i > j) {
        // If the first product is greater, print it
        printf("%d\n", i);
    } else {
        // Otherwise, print the second product
        printf("%d\n", j);
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}
