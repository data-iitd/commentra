# <START-OF-CODE>

# Declare two integer variables a and b
a, b = 0, 0

# Read two integers from user input
a, b = map(int, input().split())

# Calculate and print the result of the expression
# The expression computes the number of complete groups of (a-1) that can fit into (b-1) + (a-2)
print(((b - 1) + (a - 2)) // (a - 1))

# 