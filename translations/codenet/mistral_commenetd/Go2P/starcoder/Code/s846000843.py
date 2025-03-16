def main():
	# Read the number n from the standard input.
	n = int(input())

	# Initialize an array aa of length n to store the input integers.
	aa = [0] * n

	# Read n integers from the standard input and store them in the aa array using a for loop.
	for i in range(n):
		aa[i] = int(input())

	# Compute the cumulative sum of the aa array using the CumSum function.
	cumsum = CumSum(aa)

	# Initialize a variable ans to store the answer.
	ans = 2020202020

	# Use a for loop to iterate through the cumulative sum array, excluding the first and last elements, and compute the absolute difference between the last cumulative sum and the current cumulative sum, and the difference between the current cumulative sum and the first cumulative sum. Keep the minimum of these two differences as the answer.
	for i in range(1, len(cumsum)-1):
		# Compute the absolute difference between the last cumulative sum and the current cumulative sum.
		diff1 = abs(cumsum[len(cumsum)-1] - cumsum[i])

		# Compute the difference between the current cumulative sum and the first cumulative sum.
		diff2 = cumsum[i] - cumsum[0]

		# Keep the minimum of these two differences as the answer.
		ans = min(ans, diff1, diff2)

	# Print the answer using the print function.
	print(ans)

# The CumSum function computes the cumulative sum of an integer slice.
def CumSum(nums):
	sums = [0]

	for i in range(len(nums)):
		sums.append(sums[i]+nums[i])
	return sums

# The min function returns the minimum of a list of integers.
def min(nums):
	if len(nums) == 0:
		raise Exception("function min() requires at least one argument.")
	res = nums[0]
	for i in range(len(nums)):
		res = min(res, nums[i])
	return res

# The max function returns the maximum of a list of integers.
def max(nums):
	if len(nums) == 0:
		raise Exception("function max() requires at least one argument.")
	res = nums[0]
	for i in range(len(nums)):
		res = max(res, nums[i])
	return res

# The SortAsc function sorts an integer slice in ascending order.
def SortAsc(a):
	a.sort()
	return a

# The SortDesc function sorts an integer slice in descending order.
def SortDesc(a):
	a.sort(reverse=True)
	return a

# The GCD function returns the greatest common divisor of a and b.
def GCD(a, b):
	if b == 0:
		return a
	return GCD(b, a%b)

# The LCM function returns the least common multiple of a and b.
def LCM(a, b):
	if a == 0 and b == 0:
		return 0
	return a * b / GCD(a, b)

# The BisectLeft function returns the index where x should be inserted into a sorted slice to maintain the sort order.
def BisectLeft(nums, left, right, target):
	if left == right:
		if nums[left] == target:
			return left
		elif nums[left] < target:
			return left + 1
		else:
			return left
	mid = (left + right) / 2
	if nums[mid] == target:
		return mid
	if nums[mid] > target:
		return BisectLeft(nums, left, mid, target)
	elif nums[mid] < target:
		return BisectLeft(nums, mid+1, right, target)
	return 0

# The Permutations function returns all permutations of a slice.
def Permutations(nums):
	size = len(nums)
	result = []

	for _, n in enumerate(nums):
		rest = remove(nums, n)
		lists = Permutations(rest)
		for _, list in enumerate(lists):
			lists = append(lists, append(list, n))
			result = append(result, lists...)
	return result

# The remove function removes the first occurrence of x from a slice.
def remove(nums, x):
	result = []
	for _, n in enumerate(nums):
		if n!= x:
			result = append(result, n)
	return result

# The PowerSet function returns all subsets of a slice.
def PowerSet(nums):
	size = len(nums)
	result = []

	idx = 0
	result = append(result, [])
	idx++

	for _, n in enumerate(nums):
		max = idx
		for i in range(max):
			result = append(result, copyAndAppend(result[i], n))
			idx++
	return result

# The copyAndAppend function returns a copy of x with y appended to it.
def copyAndAppend(x, y):
	dst = [0] * (len(x)+1)
	copy(dst, x)
	dst[len(x)] = y
	return dst

# The Combination function returns all combinations of size r from a slice.
def Combination(nums, r):
	size = len(nums)
	result = []
	bi = (1 << uint(r)) - 1
	max = 1 << uint(size)
	idx = 0

	for bi < max:
		flags = bi
		s = []
		for i in range(size):
			if flags%2!= 0:
				s = append(s, nums[i])
			flags /= 2
		result = append(result, s)
		idx++
		bi = Combination2NextIndex(bi)
	return result

# The Combination2NextIndex function returns the next index of a combination.
def Combination2NextIndex(bi):
	bi = bi | (bi >> 1)
	bi = bi | (bi >> 2)
	bi = bi | (bi >> 4)
	bi = bi | (bi >> 8)
	bi = bi | (bi >> 16)
	return bi + 1

# The Fact function returns the factorial of n.
def Fact(n):
	if n == 0:
		return 1
	else:
		return n * Fact(n-1)

# The Divisors function returns all divisors of n.
def Divisors(n):
	divisors = {}
	for i in range(1, int(math.Sqrt(float(n)))+1):
		if n%i == 0:
			divisors[i] = True
			divisors[n/i] = True
	return list(divisors.keys())

# The Translate the above Go code to Python and end with comment "