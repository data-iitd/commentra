
# Import the're' module to use regular expressions
import re

# Read the input string from the console
a = input()

# Replace all occurrences of ',' in the 'a' string with a single space
a = re.sub(',','', a)

# Print the modified string to the console
print(a)

# 