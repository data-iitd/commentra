
# Define the size of the array
MAX_N = 200005

# Initialize arrays
a = [0 for i in range(MAX_N)]
pre = [0 for i in range(MAX_N)]
last = [0 for i in range(MAX_N)]

# Read the number of elements in the array
n = int(input())

# Read the elements of the array
for i in range(1,n+1):
	a[i] = int(input())

# Initialize sum of prefix and suffix arrays to zero
sumpre = 0
sumlast = 0

# Calculate prefix sum
for i in range(1,n):
	sumpre += a[i]
	pre[i] = sumpre

# Calculate suffix sum
for i in range(n,0,-1):
	sumlast += a[i]
	last[i] = sumlast

# Initialize difference as maximum long long value
d = (1 << 60)

# Find the minimum difference between prefix and suffix sums
for i in range(1,n):
	d = min(d, abs(pre[i] - last[i+1]))

# Print the minimum difference
print(d)

# 