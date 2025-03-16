import sys

# Declare arrays to store input values, prefix sums, and suffix sums
a = [0] * 200005
pre = [0] * 200005
last = [0] * 200005

# Read the number of elements
n = int(input().strip())

# Read the input values into the array 'a'
a[1:n+1] = map(int, sys.stdin.readline().strip().split())

sumpre = 0
sumlast = 0

# Calculate prefix sums and store them in 'pre' array
for i in range(1, n):
    sumpre += a[i]
    pre[i] = sumpre

# Calculate suffix sums and store them in 'last' array
for i in range(n, 1, -1):
    sumlast += a[i]
    last[i] = sumlast

# Initialize 'd' to a large value to find the minimum difference
d = 1 << 60

# Calculate the minimum absolute difference between prefix and suffix sums
for i in range(1, n):
    d = min(d, abs(pre[i] - last[i + 1]))

# Output the minimum difference found
print(d)
