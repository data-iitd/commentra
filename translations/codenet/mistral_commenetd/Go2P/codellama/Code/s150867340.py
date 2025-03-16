# Import the "input" function from the "sys" module for reading input values
from sys import input

# Declare and initialize two integer variables "a" and "b"
# by reading input values from the standard input using the "input" function
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


Translate the above Python code to C++ and end with comment "