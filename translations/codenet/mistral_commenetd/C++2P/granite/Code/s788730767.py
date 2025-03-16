

# Python code

# Define input variables and some auxiliary variables
n = int(input("Enter the value of n: "))
p = int(input("Enter the value of p: "))
a = [int(x) for x in input("Enter the elements of array a separated by spaces: ").split()]
b = 0
c = 0

# Function to calculate nPr (n choose r)
def nPr(n, r):
	# Initialize result to 1
	res = 1
	# Iterate from 0 to r and multiply result with (n-i)
	for i in range(r):
		res *= (n - i)
		# Add comment explaining what is being done
		# Multiply result with factorial of (n-i)
		# to get the value of nPr(n, r)
		#print("Calculating nPr({}, {}) = {}".format(n, r, res))
	# Return the result
	return res

# Function to calculate nCr (n choose r)
def nCr(n, r):
	# Initialize result to 1
	res = 1
	# Iterate from 0 to r and multiply result with (n-i) and divide by (i+1)
	for i in range(r):
		res *= (n - i)
		res /= (i+1)
		# Add comment explaining what is being done
		# Multiply result with factorial of (n-i) and divide by (i+1)
		# to get the value of nCr(n, r)
		#print("Calculating nCr({}, {}) = {}".format(n, r, res))
	# Return the result
	return res

# Main function
if __name__ == "__main__":
	# Read input values of n and p from the user
	# Initialize b and c to count the number of even and odd elements in the array a
	for i in range(n):
		if a[i] % 2 == 0:
			b += 1
		else:
			c += 1
		# Add comment explaining what is being done
		# Read an element from the array a and check if it is even or odd
		# Increment the corresponding counter (b for even and c for odd)

	# Calculate the sum of 2^b and c
	bsum = 1
	bsum = pow(2, b)

	# Calculate the sum of nCr(c, i) for i from 0 to c
	if p == 0:
		csum = 0
		for i in range(c+1):
			if i % 2 == 0:
				csum += nCr(c, i)
			# Add comment explaining what is being done
			# If i is even, add nCr(c, i) to csum
	else:
		csum = 0
		for i in range(c+1):
			if i % 2 == 1:
				csum += nCr(c, i)
			# Add comment explaining what is being done
			# If i is odd, add nCr(c, i) to csum

	# Multiply bsum and csum and store the result in ans
	ans = bsum * csum
	# Add comment explaining what is being done
	# Multiply bsum and csum to get the final answer

	# Print the final answer
	print(ans)

