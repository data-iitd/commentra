
import sys

# Create a Scanner object to read input from the standard input stream
sc = sys.stdin

# Read the number of elements
n = int(sc.readline())

# Initialize sums of subsets
a = 0
b = 0
c = 0

# Sum all n elements
for i in range(n):
    a += int(sc.readline())

# Sum n-1 elements
for i in range(n-1):
    b += int(sc.readline())

# Sum n-2 elements
for i in range(n-2):
    c += int(sc.readline())

# Calculate the differences
x = a - b
y = b - c

# Output the results
print(x)
print(y)

# 