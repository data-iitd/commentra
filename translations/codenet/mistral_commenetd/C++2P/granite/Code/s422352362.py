

# Read the number of elements in the array
n = int(input())

# Read the elements of the array
a = list(map(int, input().split()))

# Initialize arrays
pre = [0] * (n + 1)
last = [0] * (n + 1)

# Calculate prefix sum
sumpre = 0
for i in range(1, n):
    sumpre += a[i]
    pre[i] = sumpre

# Calculate suffix sum
sumlast = 0
for i in range(n - 1, -1, -1):
    sumlast += a[i]
    last[i] = sumlast

# Initialize difference as maximum long long value
d = (1 << 60)

# Find the minimum difference between prefix and suffix sums
for i in range(1, n):
    d = min(d, abs(pre[i] - last[i + 1]))

# Print the minimum difference
print(d)

