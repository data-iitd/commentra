
# Python 3 program to count the number of
# pairs with given sum

# Function to count pairs with given sum
def countPairs(arr, n, sum):

	# Initialize result
	result = 0

	# Consider all possible pairs
	for i in range(n):
		for j in range(i + 1, n):

			# If current pair has given sum
			if arr[i] + arr[j] == sum:
				result += 1

	return result

# Driver Code
if __name__ == '__main__':

	# Read input from stdin
	n, sum = map(int, input().split())
	arr = list(map(int, input().split()))

	# Function call
	print(countPairs(arr, n, sum))

