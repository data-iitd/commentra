#include<stdio.h>

int main() {
    # Declare variables to hold two integers and the result
    a, b, s = 0, 0, 0

    # Read two integers from user input
    scanf("%d %d", &a, &b)

    # Calculate the result using the formula: (a*b) - (a + b) + 1
    s = (a * b) - (a + b) + 1

    # Output the result to the console
    printf("%d\n", s)

    return 0 # Return 0 to indicate successful execution
}
