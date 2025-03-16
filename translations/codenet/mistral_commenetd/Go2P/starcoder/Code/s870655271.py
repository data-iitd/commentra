# Declare and initialize variables
N, M = map(int, input().split())
ans = 0

# Check if N and M are equal to 1
if N == 1 and M == 1:
	# If so, increment the ans variable
	ans += 1
elif 1 < N and 1 < M:
	# If N and M are greater than 1, calculate the area of the rectangle
	ans += (N - 2) * (M - 2)
else:
	# If N or M is equal to 1, calculate the number of points on the edge
	ans += (N * M) - 2

# Print the value of ans to the standard output
print(ans)

# Helper functions
def max(*x):
	# Find the maximum value in the slice x
	res = x[0]
	for i in range(1, len(x)):
		res = max(res, x[i])
	return res

def min(*x):
	# Find the minimum value in the slice x
	res = x[0]
	for i in range(1, len(x)):
		res = min(res, x[i])
	return res

def pow(x, y):
	# Calculate x raised to the power of y
	return x ** y

def abs(x):
	# Calculate the absolute value of x
	return x if x >= 0 else -x

def floor(x):
	# Round x down to the nearest integer
	return x - (x % 1)

# Helper type and function for sorting a slice of integers based on their absolute values
class SortBy:
	def __init__(self, x):
		self.x = x
	def __len__(self):
		return len(self.x)
	def __getitem__(self, i):
		return self.x[i]
	def __lt__(self, other):
		return abs(self.x) < abs(other.x)

# 