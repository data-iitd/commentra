
import sys # Importing the sys module for input and output operations

# Reading an integer input from the user
x = int(input())

# Using a ternary operator to determine the boolean value based on the input
bool = x == 1

# Setting the result based on the boolean value; if bool is false, result is 1, otherwise 0
result = 1 if not bool else 0

# Printing the result to the console
print(result)

# Flushing the output stream to ensure all data is written out
sys.stdout.flush()

