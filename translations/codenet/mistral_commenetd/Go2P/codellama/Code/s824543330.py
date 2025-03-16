# Import the "input" function for formatted I/O
from __future__ import print_function

def main():
    # Declare and initialize two integer variables, a and b, using input
    a, b = map(int, input().split())

    # Check if the product of a and b is even using the modulo operator (%).
    # If the result is zero, it means that a and b are both even or one of them is even and the other is a multiple of 2.
    if a*b%2 == 0:
        # If the condition is true, print the message "Even"
        print("Even")
    else:
        # If the condition is false, print the message "Odd"
        print("Odd")

if __name__ == "__main__":
    main()

# End of code
