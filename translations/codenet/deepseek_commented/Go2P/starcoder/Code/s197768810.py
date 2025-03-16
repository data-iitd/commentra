# Initialize a global scanner to read input efficiently
import sys
import math

# Read two integers n and m from the input
n, m = map(int, input().split())

# Initialize a slice to hold m integers
a = list(map(int, input().split()))

# Read m integers into the slice a and calculate their sum
sum = 0
for i in range(m):
	sum += a[i]

# Check if the sum of integers exceeds n
if sum > n:
	# Print -1 if the sum exceeds n and exit
	print(-1)
	sys.exit()

# Print the difference between n and the sum if it's within bounds
print(n - sum)

