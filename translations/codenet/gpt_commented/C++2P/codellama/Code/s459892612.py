#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    # Declare three integer variables to hold input values
    a, b, c = 0, 0, 0

    # Read three integers from standard input
    a, b, c = input("Enter three integers: ").split()

    # Check if the sum of a and b is greater than or equal to c
    if a + b >= c:
        # If the condition is true, print "Yes"
        print("Yes")
    else:
        # If the condition is false, print "No"
        print("No")

    # Return 0 to indicate successful completion of the program
    return 0
}

