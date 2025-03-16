
#include<stdio.h>
# Include the standard input output library

int main():
# Declare the main function

    a,b,c,d,i,j = input("Enter four integers: ")
    # Read four integers from the standard input and store them in variables a, b, c, and d

    i = a*b
    # Multiply variables a and b and store the result in variable i

    j = c*d
    # Multiply variables c and d and store the result in variable j

    if i > j:
        # Check if the value of i is greater than j

        print(i)
        # If true, print the value of i

    else:
        # If the condition in the if statement is false

        print(j)
        # Print the value of j

    return 0
    # End the main function with a return value of 0

