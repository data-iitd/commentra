
# Importing the Scanner class for user input
from java.util import Scanner

# Creating a Scanner object to read input from the console
sc = Scanner(System.in)

# Reading two integers from the user
a = sc.nextInt() # First integer input
b = sc.nextInt() # Second integer input

sum = 0 # Initializing a variable to hold the sum of selected integers

# Loop to iterate twice to calculate the sum
for i in range(2):
    # Check if 'a' is greater than or equal to 'b'
    if a >= b:
        sum += a # Add 'a' to the sum
        a -= 1 # Decrement 'a' by 1
    else:
        sum += b # Add 'b' to the sum
        b -= 1 # Decrement 'b' by 1

# Output the final sum to the console
print(sum)

