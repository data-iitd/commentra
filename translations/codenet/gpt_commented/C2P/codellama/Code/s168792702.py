#include <stdio.h>

int main(void) {
    # Declare three integer variables to hold the input values
    a, b, c = input("Enter three integers: ").split()

    # Check if the first number is less than the second, and the second is less than the third
    if a < b and b < c:
        print("Yes")  # If the condition is true, print "Yes"
    else:
        print("No")   # If the condition is false, print "No"

    return 0  # Return 0 to indicate successful completion of the program
}
