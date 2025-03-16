#include <stdio.h>

int main() {
    // Declare variables to hold the input values
    int N = 0; // Variable to store the first input value
    int R = 0; // Variable to store the second input value

    // Read two integers from user input
    scanf("%d %d", &N, &R);

    // Check if the first input value N is greater than or equal to 10
    if(N >= 10) {
        // If N is 10 or more, print the value of R as is
        printf("%d\n", R);
    } else {
        // If N is less than 10, calculate and print R adjusted by the difference from 10
        printf("%d\n", R + 100 * (10 - N));
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}
