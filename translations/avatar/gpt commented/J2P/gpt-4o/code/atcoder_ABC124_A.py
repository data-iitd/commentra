# Importing the sys module for user input
import sys

# Reading two integers from the user
a = int(sys.stdin.readline().strip())  # First integer input
b = int(sys.stdin.readline().strip())  # Second integer input

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

# <END-OF-CODE>
