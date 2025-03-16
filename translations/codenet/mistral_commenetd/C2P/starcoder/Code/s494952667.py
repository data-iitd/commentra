# Standard Input/Output Library
from sys import stdin, stdout

# String Library
from string import *

# Declare and initialize a character array named'str' with a size of 21
str = [' ']*21

# Declare and initialize two integer variables named 'i' and 'len'
i = 0
len = 0

# Prompt the user to enter a string
stdout.write("Enter a string: ")

# Read a string from the standard input and store it in the'str' array
stdin.readline(str, 21)

# Calculate the length of the string stored in the'str' array and assign it to the 'len' variable
len = len(str)

# Print a message to indicate that the reversed string will be printed
stdout.write("Reversed string: ")

# Use a for loop to print each character of the string in reverse order
for i in range(len-1, -1, -1):
    stdout.write(str[i])

# Print a newline character
stdout.write("\n")

# Indicate successful execution
exit(0)

