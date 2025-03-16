
from math import prod

# Take an input from the user and store it in variable 'a'
input()
a = input()

# Print the result based on the input
print(0 if a.count("1") == 0 else prod([i.count("0") + 1 for i in a.strip("0 ").split('1')]))


