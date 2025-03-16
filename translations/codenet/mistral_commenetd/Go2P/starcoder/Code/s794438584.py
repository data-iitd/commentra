# Function to find the maximum of two integers
def max(lhs, rhs):
	return max(lhs, rhs)

def main():
	# Initialize variables N and M to read input
	N, M = map(int, input().split())
	# Initialize slices values and weights of size N to read input
	values = list(map(int, input().split()))
	weights = list(map(int, input().split()))
	# Initialize 2D slice dp of size (N+1) x (M+1)
	dp = [[0 for j in range(M+1)] for i in range(N+1)]
	# Iterate through each index i from 1 to N and each index j from 0 to M
	for i in range(1, N+1):
		for j in range(0, M+1):
			# Initialize dp[i][j] with dp[i-1][j]
			dp[i][j] = dp[i-1][j]
			# If j is greater than or equal to the weight of the current index i-1,
			# update dp[i][j] with the maximum value between dp[i][j] and dp[i-1][j-weights[i-1]]+values[i-1]
			if j >= weights[i-1]:
				dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1])
	# Print the final value of dp[N][M]
	print(dp[N][M])
	# End of the code

