#include <stdio.h>

int main(void) {
    // Declare variables
    int i, N, x;
    x = 0; // Initialize x to 0 to hold the sum

    // Read an integer N from user input
    scanf("%d", &N);

    // Loop from 1 to N to calculate the sum of integers
    for(i = 1; i <= N; i++) {
        x += i; // Add the current value of i to x
    }

    // Print the calculated sum
    printf("%d\n", x);

    return 0; // Indicate that the program ended successfully
}
