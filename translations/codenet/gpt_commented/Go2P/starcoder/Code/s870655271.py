def main():
	# Declare variables for input dimensions and the answer
	N, M = map(int, input().split())
	ans = 0
	
	# Calculate the number of valid positions based on the dimensions
	if N == 1 and M == 1:
		# If both dimensions are 1, there's only one position
		ans += 1
	elif 1 < N and 1 < M:
		# If both dimensions are greater than 1, calculate the inner positions
		ans += (N - 2) * (M - 2)
	else:
		# If one dimension is 1, count the edge positions
		ans += (N * M) - 2

	# Output the calculated answer
	print(ans)

# max function returns the maximum value from a variable number of integers
def max(*x):
	res = x[0]
	for i in range(1, len(x)):
		res = max(res, x[i])
	return res

# min function returns the minimum value from a variable number of integers
def min(*x):
	res = x[0]
	for i in range(1, len(x)):
		res = min(res, x[i])
	return res

# pow function calculates x raised to the power of y
def pow(x, y): return x ** y

# abs function returns the absolute value of an integer
def abs(x): return x if x >= 0 else -x

# floor function returns the largest integer less than or equal to x
def floor(x): return x - (x % 1)

# SortBy is a type that implements sorting based on absolute values
class SortBy(list):
	def __init__(self, x):
		super().__init__(x)

	def __lt__(self, other):
		return abs(self[0]) < abs(other[0])

# 