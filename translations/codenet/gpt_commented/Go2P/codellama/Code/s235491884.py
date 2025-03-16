
# Importing the input function from the sys module
from sys import stdin

# Importing the count function from the string module
from string import count

# Reading a string from standard input
s = stdin.readline().strip()

# Counting the occurrences of the letter 'o' in the input string 's'
n = count(s, 'o')

# Calculating the result based on the count of 'o' and printing it
# The formula adds 700 to 100 times the count of 'o'
print(700 + n*100)

