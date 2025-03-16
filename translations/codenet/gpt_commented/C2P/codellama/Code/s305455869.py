#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <limits.h>
#include <math.h>

def main(argc, argv):
    # Declare variables to hold input values and the result
    a = 0
    b = 0
    ans = 0

    # Read two integers from standard input
    a = int(input())
    b = int(input())

    # Initialize the answer variable to zero
    ans = 0

    # Determine the value of ans based on the value of a
    if a >= 13:
        # If a is 13 or greater, set ans to b
        ans = b
    elif a >= 6:
        # If a is between 6 and 12, set ans to half of b
        ans = b / 2

    # Output the result
    print(ans)

    # Return 0 to indicate successful execution
    return 0

