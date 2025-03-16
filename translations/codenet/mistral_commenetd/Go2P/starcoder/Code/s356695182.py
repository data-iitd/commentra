# Initialize a scanner for reading input from stdin
import sys

# Function to read an integer from standard input
def nextInt():
	return int(input())

# Function to read multiple integers from standard input
def scanNums(len):
	# Initialize an empty slice to store the numbers
	nums = []

	# Read each number from standard input and append it to the slice
	for i in range(len):
		nums.append(int(input()))

	# Return the slice of numbers
	return nums

# Function to calculate the first pattern
def pattern1(l):
	# Calculate the value of n using the given formula
	n = (l[0]*l[3])+(l[1]*l[4])

	# Return the value of n
	return n

# Function to calculate the second pattern
def pattern2(l):
	# Calculate the maximum of l[3] and l[4]
	maxNum = max(l[3], l[4])

	# Calculate the value of n using the given formula
	n = 2 * l[2] * maxNum

	# Return the value of n
	return n

# Function to calculate the third pattern
def pattern3(l):
	# Calculate the minimum of l[3] and l[4]
	minNum = min(l[3], l[4])

	# Calculate the value of n using the given formula
	n = 2 * l[2] * minNum + doch(l)

	# Return the value of n
	return n

# Function to find the minimum of a list of numbers
def min(nums):
	# If the list is empty, panic with an error message
	if len(nums) == 0:
		raise Exception("function min() requires at least one argument.")

	# Initialize the minimum value as the first number in the list
	res = nums[0]

	# Iterate through the list and update the minimum value if necessary
	for i in range(len(nums)):
		res = min(res, nums[i])

	# Return the minimum value
	return res

# Function to find the maximum of a list of numbers
def max(nums):
	# If the list is empty, panic with an error message
	if len(nums) == 0:
		raise Exception("function max() requires at least one argument.")

	# Initialize the maximum value as the first number in the list
	res = nums[0]

	# Iterate through the list and update the maximum value if necessary
	for i in range(len(nums)):
		res = max(res, nums[i])

	# Return the maximum value
	return res

# Helper function to calculate the difference between the larger and smaller of two numbers
def doch(l):
	# If l[3] is greater than l[4], return the product of l[0] and the difference between l[3] and l[4]
	if l[3] > l[4]:
		return l[0] * (l[3] - l[4])
	else:
		# Otherwise, return the product of l[1] and the difference between l[4] and l[3]
		return l[1] * (l[4] - l[3])

# Main function to read input and call the pattern functions
def main():
	# Read the length of the input list
	len = nextInt()

	# Read the input list from standard input
	l = scanNums(len)

	# Calculate and print the minimum of the three patterns
	print(min(pattern1(l), pattern2(l), pattern3(l)))

# Call the main function
if __name__ == "__main__":
	main()

