# Read two integer values from the standard input
a, b = map(int, input().split())

# Calculate the product of "a" and "b"
product = a * b

# Check if the product is even or odd using an if statement
if product % 2 == 0:
    # If the product is even, print the message "Even" to the standard output
    print("Even")
else:
    # If the product is odd, print the message "Odd" to the standard output
    print("Odd")

# End-of-code
