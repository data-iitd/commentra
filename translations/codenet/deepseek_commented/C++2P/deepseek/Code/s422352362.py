import sys

# Read the number of elements
n = int(input().strip())

# Read the elements into a list
a = list(map(int, input().strip().split()))

# Initialize prefix and suffix sum arrays
pre = [0] * (n + 1)
last = [0] * (n + 1)

# Calculate prefix sums
sumpre = 0
for i in range(1, n):
    sumpre += a[i - 1]
    pre[i] = sumpre

# Calculate suffix sums
sumlast = 0
for i in range(n, 1, -1):
    sumlast += a[i - 1]
    last[i] = sumlast

# Find the minimum absolute difference between prefix and suffix sums
d = 2**60
for i in range(1, n):
    d = min(d, abs(pre[i] - last[i + 1]))

# Print the minimum difference
print(d)
