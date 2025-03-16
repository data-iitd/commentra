#include <stdio.h>

int main() {
    # Declare two integer variables to hold the input values
    a, b = input("Enter two integers: ").split()

    # Check if 500 times the value of 'a' is greater than or equal to 'b'
    if 500 * int(a) >= int(b):
        # If the condition is true, print "Yes"
        print("Yes")
    else:
        # If the condition is false, print "No"
        print("No")

    # Return 0 to indicate successful execution of the program
    return 0
}

