# Include the iostream library for input and output operations
# Include the string library for string operations

# Use the standard namespace to avoid prefixing standard library names with'std::'
from sys import stdin, stdout

# Read input from the user and store it in the string variable's'
s = stdin.readline().strip()

# Declare two integer variables to store the positions of 'A' and 'Z'
a, z = -1, -1

# The first for loop iterates through the string to find the position of the first occurrence of 'A'
for i in range(len(s)):
    if s[i] == 'A':
        a = i
        break

# The second for loop iterates through the string in reverse to find the position of the last occurrence of 'Z'
for i in range(len(s) - 1, -1, -1):
    if s[i] == 'Z':
        z = i
        break

# Calculate the length of the substring between the first 'A' and the last 'Z' and print it
stdout.write(str(z - a + 1) + '\n')

# 