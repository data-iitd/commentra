#include<stdio.h>

int main() {
    # Declare variables to hold input values
    a, b, c, x, y = input("Enter five integer values: ").split()

    # Double the value of c
    c *= 2

    # Check if the sum of a and b is less than or equal to c
    if a + b <= c:
        # If true, calculate and print the total cost using x and y
        print(a * int(x) + b * int(y))
    else:
        # If the sum of a and b is greater than c, check the value of x against y
        if int(x) <= int(y):
            # If x is less than or equal to y, check if b is less than or equal to c
            if b <= c:
                # If true, calculate and print the total cost considering c and the remaining b
                print(c * int(x) + (int(y) - int(x)) * int(b))
            else:
                # If b is greater than c, print the total cost using c and y
                print(c * int(y))
        else:
            # If x is greater than y, check if a is less than or equal to c
            if a <= c:
                # If true, calculate and print the total cost considering c and the remaining a
                print(c * int(y) + (int(x) - int(y)) * int(a))
            else:
                # If a is greater than c, print the total cost using c and x
                print(c * int(x))

    # Return 0 to indicate successful execution
    return 0
}

