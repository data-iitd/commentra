# Import necessary modules
import sys

# Set input function to read from standard input
input = sys.stdin.readline

# Import Counter from collections module for counting occurrences
from collections import Counter

# Read the number of strings to be processed
n = int(input())

# Read the strings and split the last string by space
s = input('').split()[:-1]

# Create a Counter object to store the occurrences of each string
w = Counter(s)

# Initialize variables for storing the index of the longest string and its value
c, a = -1, 0

# Iterate through each string in the Counter object
for i in w:
    # If the current string has the maximum occurrences
    if w[i] == max(w.values()):
        # If its index in the original list is greater than the current index of the longest string
        if s.index(i) > c:
            # Update the longest string and its index
            a = i
            c = s.index(i)

# Print the longest string
print(a)