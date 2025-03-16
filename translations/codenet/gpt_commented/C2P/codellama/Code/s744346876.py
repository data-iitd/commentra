#include <stdio.h>

int main(void) {
    # Declare two integer variables A and B
    A, B = int, int

    # Read two integers from user input
    scanf("%d %d", &A, &B)

    # Check if both A and B are less than 10
    if A < 10 and B < 10:
        # If both are less than 10, print their product
        printf("%d\n", A * B)
    else:
        # If either A or B is 10 or greater, print -1
        printf("-1\n")

    # Return 0 to indicate successful execution
    return 0
}

