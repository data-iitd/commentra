# Import necessary libraries
import sys

# Read the number of elements
n = int(sys.stdin.readline().strip())

# Initialize the array to store the input values
a = [0] * (n + 1)
# Initialize the prefix and suffix sum arrays
pre = [0] * (n + 1)
last = [0] * (n + 1)

# Read n integers into the array a
for i in range(1, n + 1):
    a[i] = int(sys.stdin.readline().strip())

# Calculate the prefix sums
sumpre = 0
for i in range(1, n):
    sumpre += a[i]
    pre[i] = sumpre

# Calculate the suffix sums
sumlast = 0
for i in range(n, 1, -1):
    sumlast += a[i]
    last[i] = sumlast

# Initialize the minimum difference to a large number
d = (1 << 60)

# Find the minimum absolute difference between prefix and suffix sums
for i in range(1, n):
    d = min(d, abs(pre[i] - last[i + 1]))

# Print the minimum difference found
print(d)

# <END-OF-CODE>
