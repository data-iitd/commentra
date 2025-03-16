# Import the map function from the built-in module
# This function is used to apply a given function to each item of an iterable

# Take three integers as input from the user
r, D, x = map(int, input().split())

# Iterate through the range of numbers from 2 to 11 (12 is excluded)
for i in range(2, 12):
    # Calculate the expression and print the integer result
    print(int(round((r ** (i - 1)) * (x + D / (1 - r)) - D / (1 - r))))

# The expression inside the loop calculates the value of a recursive formula
# r^(i-1) * (x + D / (1 - r)) - D / (1 - r)
