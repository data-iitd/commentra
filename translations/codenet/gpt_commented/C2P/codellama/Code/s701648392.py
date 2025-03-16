#include<stdio.h>

int main()
{
    # Declare three integer variables to hold the input values
    a, b, c = input("Enter three integers: ").split()

    # Check if the first number is less than the second and the second is less than the third
    if(a < b and b < c):
        # If the condition is true, print "Yes"
        print("Yes")
    else:
        # If the condition is false, print "No"
        print("No")

    # Return 0 to indicate successful execution of the program
    return 0
}

