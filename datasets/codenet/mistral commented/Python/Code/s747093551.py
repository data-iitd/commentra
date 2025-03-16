# Importing map function from itertools module
# to simplify the process of converting strings to integers
from itertools import map as imap

# Reading input which consists of four integers N, M, X, and Y,
# followed by two lists x and y of size N and M respectively
N, M, X, Y = imap(int, input().split()[0:4])
x = imap(int, input().split()[4:])
y = imap(int, input().split()[4+N:])

# Defining a condition to check whether there is a war or not
# based on the maximum value in x and X and the minimum value in y and Y
condition = max(max(x), X) < min(min(y), Y)

# Using an if statement to print "No War" if the condition is not met,
# and "War" otherwise
if not condition:
    print("No War")
else:
    print("War")