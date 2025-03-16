import math

# Read the number of successful and failed runs from the standard input
n, m = map(int, input().split())

# Calculate the total time in milliseconds for the successful and failed runs
x = m * 1900 + (n - m) * 100

# Print the result of the expression (total time * 2^m)
print(x * int(math.pow(2, m)))

# <END-OF-CODE>
