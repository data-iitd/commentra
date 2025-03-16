#include <stdio.h>

int main(void) {
    # Declare two integer variables h and r
    h, r = int(input()), int(input())

    # Compare the value of r with -h
    if r > -h:
        # If r is greater than -h, print "1"
        print("1\n")
    elif r == -h:
        # If r is equal to -h, print "0"
        print("0\n")
    else:
        # If r is less than -h, print "-1"
        print("-1\n")

    # Return 0 to indicate successful completion of the program
    return 0
}

