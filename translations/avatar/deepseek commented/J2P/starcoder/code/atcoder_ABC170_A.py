
# Importing the required libraries
import sys

# Reading the input from the console
input_array = sys.stdin.readline().split(" ")

# Initializing a variable to store the count of non-zero elements
result = 0

# Iterating through the array and updating the result
for str in input_array:
    result += 1
    if "0" == str: break

# Printing the result to the console
print(result)

# 