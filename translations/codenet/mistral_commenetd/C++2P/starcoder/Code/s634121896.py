
# Python 3 program to solve the problem

# Function to calculate the number of ways to reach the last index
def solve(nums):
	# Initialize the variables to keep track of the last number and the previous index of the last number
	last = 0
	prev = {}
	# Initialize the vector to store the prefix sum of the number of ways to reach each index
	dp = [0]*(len(nums)+1)
	# Set the initial value of the prefix sum at index 0
	dp[0] = 1
	# Iterate through the numbers from 1 to n
	for i in range(1, len(nums)+1):
		# Calculate the prefix sum at the current index by adding the number of ways to reach the previous index (if the previous number is not the same as the current number)
		dp[i] = dp[i-1] + (prev.get(nums[i-1], 0)!=i-1)
		# Update the map
		prev[nums[i-1]] = i
	# Return the result
	return dp[len(nums)]

# Driver code
if __name__ == '__main__':
	# Read the number of test cases (if any) or the main input
	n = int(input())
	# Initialize the vector to store the numbers
	nums = [0]*n
	# Read the numbers from the input
	for i in range(n):
		nums[i] = int(input())
	# Print the result
	print(solve(nums))

