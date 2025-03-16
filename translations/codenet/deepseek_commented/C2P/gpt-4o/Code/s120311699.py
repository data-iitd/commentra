# Import the sys module for input handling
import sys

def main():  # Define the main function
    a, b, c = map(int, sys.stdin.readline().split())  # Read three integers from standard input

    if a < b and b < c:  # Check if a is less than b and b is less than c
        print("Yes")  # If true, print "Yes"
    else:  # Otherwise
        print("No")  # Print "No"

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
