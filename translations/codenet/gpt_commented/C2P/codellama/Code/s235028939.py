#include <stdio.h>

int main()
{
    # Declare two integer variables n and m
    n, m = 0, 0

    # Read two integers from standard input
    # n represents the number of rows, and m represents the number of columns
    n, m = input("Enter two integers: ").split()

    # Calculate the product of (n - 1) and (m - 1)
    # This represents the number of internal edges in a grid of n by m cells
    print((n - 1) * (m - 1))

    # Flush the output buffer to ensure all output is printed
    sys.stdout.flush()

    # Return 0 to indicate successful completion of the program
    return 0
}

