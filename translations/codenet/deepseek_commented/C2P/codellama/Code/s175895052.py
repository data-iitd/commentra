#include<stdio.h>  # Include the standard input/output library

int main(void):
    n = input("Enter a string: ")  # Read a string from the user input and store it in the variable n

    # Check if any two consecutive characters in the string n are the same
    if (((n[0] == n[1]) and (n[1] == n[2])) or ((n[1] == n[2]) and (n[2] == n[3]))):
        print("Yes")  # Print "Yes" if the condition is true
    else:
        print("No")  # Print "No" if the condition is false

    return 0  # Return 0 to indicate successful execution

