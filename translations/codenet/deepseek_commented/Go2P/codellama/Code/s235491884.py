
# Importing the input function from the sys module
from sys import stdin

# Reading input from the user and storing it in the variable s
s = stdin.readline().strip()

# Counting the number of occurrences of "o" in the string s and storing the result in n
n = s.count("o")

# Printing the final score based on the count of "o" characters
print(700 + n*100)

