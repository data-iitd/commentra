
# Importing the 'sys' module for reading input from the user
import sys

# Reading a string input from the user and storing it in variable 's'
s = sys.stdin.readline().strip()

# Replacing all occurrences of "2017" with "2018" in the input string and printing the result
print(s.replace("2017", "2018"))

