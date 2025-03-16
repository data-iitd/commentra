
# Importing the'sys' module
import sys

# Reading the number of elements in the array from the user input
n = int(input())

# Creating an integer array 'a' of size 'n' to store the input elements
a = [0] * n

# Initializing the XOR result to 0
r = 0

# Reading the elements of the array 'a' from the user input and performing XOR operation
for i in range(n):
# Reading the next integer from the user input
a[i] = int(input())

# Performing XOR operation between 'r' and the current element 'a[i]' and updating the value of 'r'
r ^= a[i]

# Printing the XOR result
for i in range(n):
# If it's not the first element, print a space before the current element
if i!= 0:
print(" ", end="")

# Printing the XOR result of 'r' and the current element 'a[i]'
print(r ^ a[i], end="")

# Printing the end of code marker
print("