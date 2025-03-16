#include<stdio.h>  # Include the standard input/output library

int main(void):  # Define the main function

    a, b, n = input("Enter two numbers: ").split()  # Read input values
    n = (int(a) + int(b)) / 2  # Calculate the average
    print(n)  # Print the result
    return 0  # Return from main function

