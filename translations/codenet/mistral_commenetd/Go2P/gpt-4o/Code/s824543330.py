# Import the sys module for input
import sys

def main():
    # Read two integers from input
    a, b = map(int, sys.stdin.readline().split())

    # Check if the product of a and b is even using the modulo operator (%).
    # If the result is zero, it means that a and b are both even or one of them is even and the other is a multiple of 2.
    if a * b % 2 == 0:
        # If the condition is true, print the message "Even"
        print("Even")
    else:
        # If the condition is false, print the message "Odd"
        print("Odd")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
