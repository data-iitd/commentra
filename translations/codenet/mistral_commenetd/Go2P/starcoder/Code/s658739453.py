
# Import big package for handling large integers
import math
import sys

# Define a constant 'd' as a big.Int
d = int(math.pow(10, 9) + 7)

# Read the first integer 'n' from the standard input
n = int(sys.stdin.readline())

# Read the second integer 'p' from the standard input
p = int(sys.stdin.readline())

# Initialize an empty map'mdans' for storing distinct numbers
mdans = {}

# Read 'p' distinct numbers from the standard input and store them in the map'mdans'
for i in range(p):
	n1 = int(sys.stdin.readline())
	mdans[n1] = n1

# Initialize an array 'dp' of size 'n+1' with a default value of '0'
dp = [0] * (n + 1)
dp[0] = 1
dp[1] = 1

# Initialize the third element of the array 'dp' with a value of '0' if the number '1' is present in the map'mdans'
if 1 in mdans:
	dp[1] = 0

# Calculate the remaining elements of the array 'dp' using the previous elements
for i in range(2, n + 1):
	if i in mdans:
		continue
	dp[i] = (dp[i - 1] + dp[i - 2]) % d

# Print the final result
print(dp[n])

# 