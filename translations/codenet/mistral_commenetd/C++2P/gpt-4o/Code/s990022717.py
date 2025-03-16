# Initialize variables
n, k, x, y = map(int, input().split())  # Read input values for n, k, x, and y from standard input

sum = 0  # Initialize sum variable to 0

# Iterate through numbers from 1 to n
for i in range(1, n + 1):
    # If the current number i is greater than k, add y to the sum
    if i > k:
        sum += y
    # Otherwise, add x to the sum
    else:
        sum += x

# Output the final sum value to the standard output
print(sum)

# <END-OF-CODE>
