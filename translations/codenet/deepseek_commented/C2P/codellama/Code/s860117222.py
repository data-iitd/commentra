#include <stdio.h>  # Include the standard input/output library

def main():  # Define the main function
    a, b, c = map(int, input().split())  # Read three integers from the user
    d = c - a - b  # Calculate the difference between c and the sum of a and b
    if (d > 0) and (4 * a * b < d * d):  # Check if the difference is positive and satisfies the specific condition
        print("Yes")  # Print "Yes" if the condition is met
    else:
        print("No")  # Print "No" otherwise

if __name__ == "__main__":  # Check if the program is being run directly
    main()  # Call the main function

