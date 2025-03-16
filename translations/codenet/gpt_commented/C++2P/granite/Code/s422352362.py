
import sys

# Read the number of elements
n = int(input())

# Read the input values into the array 'a'
a = list(map(int, input().split()))

# Initialize prefix sums and suffix sums
pre = [0] * n
last = [0] * n

# Calculate prefix sums and store them in 'pre' array
sumpre = 0
for i in range(1, n):
    sumpre += a[i]
    pre[i] = sumpre

# Calculate suffix sums and store them in 'last' array
sumlast = 0
for i in range(n-1, 0, -1):
    sumlast += a[i]
    last[i] = sumlast

# Initialize 'd' to a large value to find the minimum difference
d = sys.maxsize

# Calculate the minimum absolute difference between prefix and suffix sums
for i in range(1, n):
    d = min(d, abs(pre[i] - last[i+1]))

# Output the minimum difference found
print(d)

