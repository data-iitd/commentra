import sys

# Global variables to store input values
N, ss, ans, A, B, C = 0, 0, 0, 0, 0, 0

# Main function to execute the program
def main():
	# Read the input values for N, A, B, and C
	N, A, B, C = map(int, sys.stdin.readline().split())

	# Initialize the array to store the values and a dp array for choices
	arr = list(map(int, sys.stdin.readline().split()))
	dp = [0] * N
	ans = 10000
	ss = A + B + C

	# Start the depth-first search to find the minimum cost
	dfs(dp, 0, arr)

	# Print the minimum cost found
	print(ans)

# Depth-first search function to explore different combinations of choices
def dfs(dp, times, arr):
	if times >= N:
		global ans
		ans = min(ans, calc(dp, arr))
		return

	for i in range(4):
		dp[times] = i
		dfs(dp, times+1, arr)

# Function to calculate the cost based on the chosen combinations
def calc(dp, arr):
	cost, AA, BB, CC = 0, 0, 0, 0

	# Create a memoization array to count the occurrences of each choice
	memo = [0] * 4
	for i in range(len(dp)):
		memo[dp[i]] += 1
		if dp[i] == 1:
			AA += arr[i]
		elif dp[i] == 2:
			BB += arr[i]
		elif dp[i] == 3:
			CC += arr[i]
	cost += abs(A-AA) + abs(B-BB) + abs(C-CC)

	# Add additional cost for each choice that appears more than once
	for i in range(1, 4):
		a = memo[i]
		if a < 1:
			cost += 10000
		else:
			cost += (a - 1) * 10

	return cost

# Helper functions to read input, calculate minimum, and absolute value
def nextLine():
	return sys.stdin.readline().strip()

def min(a, b):
	if a < b:
		return a
	return b

def abs(a):
	if a < 0:
		return a * -1
	return a

# 