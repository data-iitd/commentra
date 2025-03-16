
# Declare arrays to store input values, prefix sums, and suffix sums
a = [0] * 200005
pre = [0] * 200005
last = [0] * 200005

# Read the number of elements
n = int(input())

# Read the input values into the array 'a'
for i in range(1, n + 1):
    a[i] = int(input())

# Calculate prefix sums and store them in 'pre' array
sumpre = 0
for i in range(1, n):
    sumpre = sumpre + a[i]
    pre[i] = sumpre

# Calculate suffix sums and store them in 'last' array
sumlast = 0
for i in range(n, 0, -1):
    sumlast = sumlast + a[i]
    last[i] = sumlast

# Initialize 'd' to a large value to find the minimum difference
d = (1 << 60)

# Calculate the minimum absolute difference between prefix and suffix sums
for i in range(1, n):
    d = min(d, abs(pre[i] - last[i + 1]))

# Output the minimum difference found
print(d)

