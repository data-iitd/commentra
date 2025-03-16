# Python version of the given Java code

# Importing the Scanner class for user input (in Python, we use the built-in input function)

# Reading two integers from the user
a = int(input())  # First integer input
b = int(input())  # Second integer input

sum = 0  # Initializing a variable to hold the sum of selected integers

# Loop to iterate twice to calculate the sum
for i in range(2):
    # Check if 'a' is greater than or equal to 'b'
    if a >= b:
        sum += a  # Add 'a' to the sum
        a -= 1  # Decrement 'a' by 1
    else:
        sum += b  # Add 'b' to the sum
        b -= 1  # Decrement 'b' by 1

# Output the final sum to the console
print(sum)
