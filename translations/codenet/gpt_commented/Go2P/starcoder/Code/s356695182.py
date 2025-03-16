# Initialize a new scanner to read from standard input
import sys

sc = sys.stdin

# nextInt reads the next integer from standard input
def nextInt():
	sc.readline() # Scan the next line of input
	return int(sc.readline()) # Convert the scanned text to an integer

# scanNums reads a specified number of integers from standard input and returns them as a slice
def scanNums(len):
	nums = []
	for i in range(len):
		nums.append(nextInt()) # Read an integer from standard input
	return nums # Return the slice of integers

# pattern1 calculates a specific pattern based on the first five integers in the slice
def pattern1(l):
	return l[0]*l[3] + l[1]*l[4] # Calculate the result based on the formula

# pattern2 calculates another pattern based on the maximum of the last two integers
def pattern2(l):
	return 2*l[2]*max(l[3], l[4]) # Calculate the result using the maximum value

# pattern3 calculates a third pattern that combines the minimum value and a function call
def pattern3(l):
	return 2*l[2]*min(l[3], l[4]) + doch(l) # Calculate the result using the minimum value and doch function

# min returns the minimum value from a variable number of integer arguments
def min(nums):
	if len(nums) == 0:
		raise Exception("function min() requires at least one argument.") # Panic if no arguments are provided
	res = nums[0] # Initialize the result with the first argument
	for i in range(len(nums)):
		res = min(res, nums[i]) # Update the result to the minimum value
	return res # Return the minimum value

# max returns the maximum value from a variable number of integer arguments
def max(nums):
	if len(nums) == 0:
		raise Exception("function max() requires at least one argument.") # Panic if no arguments are provided
	res = nums[0] # Initialize the result with the first argument
	for i in range(len(nums)):
		res = max(res, nums[i]) # Update the result to the maximum value
	return res # Return the maximum value

# doch calculates a value based on the difference between the last two integers in the slice
def doch(l):
	if l[3] > l[4]:
		return l[0] * (l[3] - l[4]) # Return the product if the fourth integer is greater
	else:
		return l[1] * (l[4] - l[3]) # Return the product if the fifth integer is greater

# main function where the program execution begins
def main():
	len = 5 # Define the number of integers to read
	l = scanNums(len) # Read the integers into a slice
	# Print the minimum value from the three calculated patterns
	print(min(pattern1(l), pattern2(l), pattern3(l)))

if __name__ == "__main__":
	main()

