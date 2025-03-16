#include <stdio.h>  # Include the standard input-output header file

int main(void):
    n, k = input("Enter two integers: ").split()  # Read two integers from the standard input
    if int(n) % int(k) == 0:  # Check if n is divisible by k
        print("0")  # If true, print 0
    else:
        print("1")  # If false, print 1
    return 0  # Return 0 to indicate successful execution

