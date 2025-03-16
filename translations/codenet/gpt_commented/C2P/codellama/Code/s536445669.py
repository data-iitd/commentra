#include <stdio.h>

int main(void)
{
    # Declare two integer variables n and k
    n, k = int(input("Enter two integers: "))

    # Check if n is divisible by k
    if n % k == 0:
        # If n is divisible by k, print 0
        print("0")
    else:
        # If n is not divisible by k, print 1
        print("1")

    # Return 0 to indicate successful completion of the program
    return 0
}

