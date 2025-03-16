#include<stdio.h>

int main(void) {
    // Declare variables to hold two integers and their average
    int a, b, n;

    // Read two integers from user input
    scanf("%d %d", &a, &b);

    // Calculate the average of the two integers
    n = (a + b) / 2;

    // Print the calculated average
    printf("%d\n", n);

    // Return 0 to indicate successful completion of the program
    return 0;
}
