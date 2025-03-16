#include<iostream>  # Include the iostream library for input and output operations
#include<string>    # Include the string library for handling strings
#include<vector>     # Include the vector library for handling dynamic arrays
#include<algorithm>  # Include the algorithm library for standard algorithms
using namespace std;  # Use the standard namespace for easier access to library functions

def main():  # Declare the main function, which is the entry point of the program
    # Declare four integer variables to store input values
    a, b, c, d = 0, 0, 0, 0

    # Read input values from the user using cin
    a, b, c, d = input("Enter four integers: ").split()

    # Check if the condition is true
    if (a*b%2==1 and (c+d)%2==1):
        # If the condition is true, print "No" to the output stream
        print("No")
    # If the condition is false, print "Yes" to the output stream
    else:
        print("Yes")

# 