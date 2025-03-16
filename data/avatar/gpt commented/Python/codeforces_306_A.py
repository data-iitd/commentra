# Read two integers from input: n (total items) and m (number of groups)
n, m = map(int, input().split())

# Calculate the quotient (q) and remainder (r) when n is divided by m
q = n // m  # Number of items each group will get
r = n % m   # Remaining items after equal distribution

# Create a list 'a' initialized with 'm' elements, each set to the quotient 'q'
a = [q] * m

# Distribute the remainder 'r' among the first 'r' groups
for i in range(r):
    a[i] += 1  # Increment the count for the first 'r' groups by 1

# Print the final distribution of items in each group
for i in range(m):
    print(a[i], end=' ')  # Print each group's item count on the same line
