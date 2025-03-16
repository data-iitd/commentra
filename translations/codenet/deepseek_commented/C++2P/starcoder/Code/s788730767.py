
# Python 3 program to find the number of
# subsets with even and odd numbers
# in a given set of n elements

# Function to calculate nPr
def nPr(n, r):
	res = 1
	for i in range(r):
		res = res * (n - i)
	return res

# Function to calculate nCr
def nCr(n, r):
	res = 1
	for i in range(r):
		res = res * (n - i)
		res = res / (i + 1)
	return res

# Function to find the number of subsets
# with even and odd numbers
def findSubsets(a, n, p):

	# Count the number of even and odd numbers
	b = 0
	c = 0
	for i in range(n):
		if (a[i] % 2 == 0):
			b += 1
		else:
			c += 1

	# Calculate the number of subsets with even and odd numbers
	bsum = pow(2, b)
	csum = 0

	if (p == 0):

		# Sum combinations where the number of elements is even
		for i in range(c + 1):
			if (i % 2 == 0):
				csum += nCr(c, i)

	else:

		# Sum combinations where the number of elements is odd
		for i in range(c + 1):
			if (i % 2 == 1):
				csum += nCr(c, i)

	# Calculate the final answer as the product of bsum and csum
	ans = bsum * csum
	return ans

# Driver Code
if __name__ == '__main__':
	n = 5
	a = [1, 2, 3, 4, 5]
	p = 0
	print(findSubsets(a, n, p))

