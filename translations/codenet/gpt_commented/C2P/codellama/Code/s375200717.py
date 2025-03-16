#include<stdio.h>

int main(void) {
    # Declare variables for input number, loop counter, and a temporary variable
    n, i, a = 0, 0, 0

    # Read an integer input from the user
    scanf("%d", &n)

    # Loop from 1 to n (inclusive)
    for i in range(1, n+1):
        # Assign the current loop index to a
        a = i

        # Check if the current number is divisible by 3
        if(a % 3 == 0):
            # If divisible by 3, print the number
            print(" %d" % i, end="")
        else:
            # If not divisible by 3, check if it contains the digit '3'
            for a in range(a, 0, -1):
                # Check if the last digit of a is 3
                if(a % 10 == 3):
                    # If it contains the digit '3', print the number
                    print(" %d" % i, end="")
                    # Set a to 0 to exit the loop
                    a = 0

    # Print a newline character after all numbers have been processed
    print()

    # Return 0 to indicate successful completion of the program
    return 0
}

