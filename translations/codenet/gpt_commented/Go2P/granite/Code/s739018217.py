
import math

# Read input values for n and m from the standard input
n, m = map(int, input().split())

# Calculate the total time required to solve the problems
# The time for hard problems is 1900 each, and for easy problems is 100 each
x = m*1900 + (n-m)*100

# Calculate the total number of ways to solve the problems
# This is done by multiplying the total time by 2 raised to the power of m (the number of hard problems)
print(x * int(math.pow(2.0, float(m))))

