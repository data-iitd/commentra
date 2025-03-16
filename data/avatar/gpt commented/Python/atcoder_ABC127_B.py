# Read input values for r, D, and x from the user
r, D, x = map(int, input().split())

# Iterate over a range of values from 2 to 11 (inclusive)
for i in range(2, 12):
    # Calculate and print the result based on the formula
    # The formula computes a value using the current iteration index i,
    # the input values r, D, and x, and prints the integer result
    print(int((r ** (i - 1)) * (x + D / (1 - r)) - D / (1 - r)))
