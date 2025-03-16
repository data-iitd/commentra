#include <stdio.h>

int main(void) {
    # Declare variables to hold the input number and the sum
    n, sum = 0, 0

    # Read an integer input from the user
    scanf("%d", &n)

    # Calculate the sum of the first n natural numbers using the formula n*(n+1)/2
    sum = (n * (n + 1)) / 2

    # Print the calculated sum to the console
    printf("%d\n", sum)

    # Return 0 to indicate successful completion of the program
    return 0
}

