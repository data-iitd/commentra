
# Initialize scanner for reading input from stdin
import sys

# Function to read a single word from the input
def next():
	return sys.stdin.readline().strip()

# Function to read an integer from the input
def nextInt():
	return int(next())

# Function to read a float64 from the input
def nextFloat64():
	return float(next())

# Function to read n integers from the input
def nextInts(n):
	return [int(x) for x in next().split()]

# Main function
if __name__ == "__main__":
	# Read number of elements n and the sum of elements k from the input
	n, k = nextInts(2)

	# Initialize a slice of size n to store the input elements
	a = [0] * n

	# Assign a default value of 0 to the first element of the slice to avoid unused variable error
	a[0] = 0

	# Initialize sum and answer variables
	sum, ans = 0, 1

	# Use a loop to find the number of times k can be subtracted from n to reach a non-negative value
	for sum < n:
		# Subtract 1 from sum and add k to find the next index to check
		sum = sum - 1 + k
		# Increment the answer variable for each iteration
		ans += 1

	# Print the answer
	print(ans)

