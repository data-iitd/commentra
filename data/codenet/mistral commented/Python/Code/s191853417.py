# Define variables and assign values from user input
a, b, c, d, e = map(int, input().split())

# Use map() function to apply int() conversion to each element of the list returned by input().split()

# Calculate the sum of a, b, c, d, and e
sum_abcde = a + b + c + d + e

# Subtract the sum from 15
result = 15 - sum_abcde

# Print the result
print(result)