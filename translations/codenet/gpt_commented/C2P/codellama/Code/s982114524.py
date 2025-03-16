#include <stdio.h>

int main(void) {
    # Declare variables
    i, N, x = 0
    x = 0 # Initialize x to 0 to hold the sum

    # Read an integer N from user input
    scanf("%d", &N)

    # Loop from 1 to N to calculate the sum of integers
    for i in range(1, N+1):
        x += i # Add the current value of i to x

    # Print the calculated sum
    printf("%d\n", x)

    return 0 # Indicate that the program ended successfully
}
