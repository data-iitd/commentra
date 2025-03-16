# Importing the sys module for reading input
import sys

# Reading input from the user
s = sys.stdin.readline().strip()  # Using readline to read input and strip any extra whitespace

# Counting the number of occurrences of "o" in the string s
n = s.count("o")

# Printing the final score based on the count of "o" characters
print(700 + n * 100)  # Final score calculation

# <END-OF-CODE>
