
# Python 3 program to count all possible
# pairs of numbers whose last digit
# is equal to the first digit

# Function to count pairs
def countPairs(n):

	# Initialize a 10x10 2D array 'cnt' with zeroes
	cnt = [[0 for i in range(10)] for j in range(10)]

	# Iterate through each number from 1 to n
	for i in range(1, n+1):

		# Extract the last digit 'b' and the digit before last 'a' from the number 'i'
		b = i % 10
		a = i

		# While 'a' has more digits than one, extract the digit before last one
		while a >= 10:
			a = a // 10

		# Increment the count of 'a'th row and 'b'th column in the 'cnt' array
		cnt[a][b] += 1

	# Initialize answer variable 'ans' with zero
	ans = 0

	# Iterate through each row and column from 1 to 9
	for i in range(1, 10):
		for j in range(1, 10):

			# Multiply the count of 'i'th row and 'j'th column with the count of 'j'th row and 'i'th column
			# and add it to the answer
			ans += cnt[i][j] * cnt[j][i]

	# Return the final answer
	return ans

# Driver Code
if __name__ == '__main__':

	# Read the number of test cases
	n = int(input())

	# Call the function to count pairs
	ans = countPairs(n)

	# Print the final answer
	print(ans)

