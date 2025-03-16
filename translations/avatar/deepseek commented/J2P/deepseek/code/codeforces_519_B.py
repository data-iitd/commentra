import sys

# Read the number of elements
n = int(input().strip())

# Initialize sums of subsets
a = 0
b = 0
c = 0

# Sum all n elements
for _ in range(n):
    a += int(input().strip())

# Sum n-1 elements
for _ in range(n - 1):
    b += int(input().strip())

# Sum n-2 elements
for _ in range(n - 2):
    c += int(input().strip())

# Calculate the differences
x = a - b
y = b - c

# Output the results
print(x)
print(y)
