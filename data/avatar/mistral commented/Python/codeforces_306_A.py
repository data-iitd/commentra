# Read the input from the user
n, m = map(int, input().split())

# Calculate the quotient and remainder of n divided by m
q = n // m
r = n % m

# Initialize the a list with q repeated m times
a = [q] * m

# Increment the corresponding elements in the a list for the remaining elements
for i in range(r):
    a[i] += 1

# Print each element of the a list separated by a space
for i in range(m):
    print(a[i], end=' ')
