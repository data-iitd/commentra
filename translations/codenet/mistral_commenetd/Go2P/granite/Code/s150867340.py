
# Import the "sys" module for reading input values from the standard input
import sys

# Read input values from the standard input using the "input" function
a = int(input())
b = int(input())

# Calculate the product of "a" and "b" and store it in a new variable "product"
product = a * b

# Check if the product is even or odd using an if statement
if product % 2 == 0:
    # If the product is even, print the message "Even" to the standard output
    print("Even")
else:
    # If the product is odd, print the message "Odd" to the standard output
    print("Odd")

# End of code