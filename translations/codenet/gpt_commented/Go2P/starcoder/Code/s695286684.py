# Importing the're' package for regular expression operations
import re

# Reading a string input from the user
s = input()

# Replacing all occurrences of "2017" with "2018" in the input string and printing the result
print(re.sub("2017", "2018", s))

# 