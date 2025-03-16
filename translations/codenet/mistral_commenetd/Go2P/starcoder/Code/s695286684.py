# Import the `re` package for regular expression operations.
import re

# Define a variable `s` of type `str` to store the user input.
s = ""

# Read a string input from the standard input and store it in the variable `s`.
s = input("Enter a string: ")

# Replace all occurrences of the string "2017" in the string `s` with the string "2018".
s = re.sub("2017", "2018", s)

# Print the modified string to the standard output.
print("Modified string:", s)

# End of code.

