# Read three integers r, D, and x from input
r, D, x = map(int, input().split())

# Loop from 2 to 11 (inclusive)
for i in range(2, 12):
    # Calculate the value using the given formula and print the integer result
    result = int((r ** (i - 1)) * (x + D / (1 - r)) - D / (1 - r))
    print(result)
