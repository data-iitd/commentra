# This is the main function where the program starts execution.
# It reads two integers N and M from the standard input.
# Depending on the values of N and M, it calculates the number of cells in the grid.
# Finally, it prints the result to the standard output.
def main():
	N, M = map(int, input().split())
	# If both N and M are 1, there is only one cell, so the answer is 1.
	if N == 1 and M == 1:
		ans = 1
	# If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
	elif 1 < N and 1 < M:
		ans = (N - 2) * (M - 2)
	# If either N or M is 1, the number of cells is (N*M) - 2.
	else:
		ans = (N * M) - 2
	print(ans)

# This function returns the maximum value among the given integers.
def max(*x):
	res = x[0]
	for i in range(1, len(x)):
		res = max(res, x[i])
	return res

# This function returns the minimum value among the given integers.
def min(*x):
	res = x[0]
	for i in range(1, len(x)):
		res = min(res, x[i])
	return res

# This function returns x raised to the power of y.
def pow(x, y):
	return x ** y

# This function returns the absolute value of x.
def abs(x):
	return abs(x)

# This function returns the floor value of x.
def floor(x):
	return math.floor(x)

# This type is a slice of integers that can be sorted by their absolute values.
class SortBy(list):
	# Len returns the length of the slice.
	def Len(self):
		return len(self)

	# Swap swaps the elements with indexes i and j.
	def Swap(self, i, j):
		self[i], self[j] = self[j], self[i]

	# Less returns true if the absolute value of the element at index i is less than the absolute value of the element at index j.
	def Less(self, i, j):
		return abs(self[i]) < abs(self[j])

