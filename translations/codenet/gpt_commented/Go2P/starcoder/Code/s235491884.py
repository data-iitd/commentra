# Import the'string' module
import string

# Read a string from standard input
s = input()

# Count the occurrences of the letter 'o' in the input string's'
n = s.count('o')

# Calculate the result based on the count of 'o' and print it
# The formula adds 700 to 100 times the count of 'o'
print(700 + n*100)

# 