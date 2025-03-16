

# Read the number of elements 'n' from the standard input
n = int(input())

# Allocate memory for two arrays 'dp' and 'h' of size 'n'
dp = [0] * n
h = [0] * n

# Read the height of each element from the standard input
for i in range(n):
	h[i] = int(input())

# Initialize the first element of 'dp' to 0
dp[0] = 0

# Iterate through the array 'dp' from the second element to the last
for i in range(1, n):
	# Calculate the cost to reach the current index 'i' from the previous index 'i - 1'
	if i == 1:
		dp[1] = abs(h[1] - h[0])
	# Calculate the minimum cost to reach the current index 'i' from the previous index 'i - 1' or the previous previous index 'i - 2'
	else:
		dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]))

# Print the minimum cost to reach the last index 'n - 1'
print(dp[n - 1])

