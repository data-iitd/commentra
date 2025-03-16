
# Importing the'sys' module for reading input from the console
import sys

# Reading an integer input from the user which determines the size of the character array
n = int(sys.stdin.readline())

# Creating a character array of size 'n'
c = [None] * n

# Filling the character array with letters starting from 'a' (ASCII 97)
for i in range(4): # Looping through the first 4 positions
    for j in range(i, n, 4): # Filling every 4th position starting from 'i'
        c[j] = chr(97 + i) # Assigning the character corresponding to ASCII value 'p'

# Printing the filled character array to the console
for i in range(n):
    print(c[i], end='') # Outputting each character in the array

# 