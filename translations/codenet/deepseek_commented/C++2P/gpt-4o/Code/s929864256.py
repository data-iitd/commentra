# Importing the necessary library
import sys

# Reading two long long integers from standard input
a, b = map(int, sys.stdin.readline().split())

# Compute the maximum value among a+b, a-b, and a*b
print(max(a + b, max(a - b, a * b)))  # Print the maximum value

# End of code
# <END-OF-CODE>
