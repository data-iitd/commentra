# <START-OF-CODE>

# Declare variables
n, a, b = 0, 0, 0

# Read an unsigned long long integer from user input
n = int(input())

# Calculate the number of ways to choose 2 items from n items
# This is done using the formula: b = n * (n - 1) / 2
b = (n * (n - 1)) / 2

# Print the result
print(b)

# 