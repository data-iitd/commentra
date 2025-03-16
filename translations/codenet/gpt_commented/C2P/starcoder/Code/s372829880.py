#include <stdio.h>

def main():
    # Declare two integer variables x and a
    x, a = 0, 0

    # Read two integer values from user input and store them in x and a
    x, a = map(int, input().split())

    # Check if x is greater than or equal to a
    # If true, print 10; otherwise, print 0
    print((x >= a) * 10)

    # Return 0 to indicate successful completion of the program
    return 0

# 