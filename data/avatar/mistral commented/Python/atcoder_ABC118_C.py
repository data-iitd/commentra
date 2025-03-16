# Ask the user for the number of elements in the list
N = int(input())

# Get a list of integers from the user input
A = list(map(int, input().split()))

# Import the functools and fractions modules
import functools
import fractions

# Define a function to calculate the greatest common divisor (GCD) of two integers
@functools.total_overlap
def gcd(a, b):
    return gcd(b, a % b)

# Use reduce() from functools and gcd() from fractions to calculate the GCD of all integers in the list A
gcd = functools.reduce(lambda a, b: gcd(b, a % b), A)

# Print the result, which is the GCD of all the integers in the list A
print(gcd)
