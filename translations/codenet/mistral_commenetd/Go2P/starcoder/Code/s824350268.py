# Constants definition
initial_buf_size = 10000
max_buf_size = 1000000
mod = 1e9 + 7

# Variables definition and initialization
sc = bufio.Scanner(sys.stdin)
sc.bufsize = initial_buf_size
sc.maxbuf = max_buf_size

# Main function
def main():
	# Read the first integer from the standard input
	N = get_int()

	# Calculate the square root of N
	sqrt_N = int(math.sqrt(N))

	# Initialize the minimum number with N
	min = N

	# Iterate through all numbers from 1 to the square root of N
	for i in range(1, sqrt_N + 1):
		# Check if N is divisible by i
		if N % i!= 0:
			continue

		# Calculate the number of divisors of i and N
		num = i + (N // i) - 2

		# Update the minimum number if the current number is smaller
		if num < min:
			min = num
	# Print the minimum number
	print(min)

# Define a Graph data structure
class Graph:
	def __init__(self, n):
		self.n = n
		self.edges = [[] for _ in range(n)]

	def add_edge(self, u, v):
		self.edges[v].append(u)
		self.edges[u].append(v)

# Initialize a new Graph with n vertices
def new_graph(n):
	return Graph(n)

# Depth First Search function
def dfs(c, edges, visited):
	# Mark the current vertex as visited
	visited[c] = True

	# Iterate through all neighbors of the current vertex
	for v in edges[c]:
		# If the neighbor is already visited, skip it
		if visited[v]:
			continue

		# Recursively call DFS for the neighbor
		dfs(v, edges, visited)

# Helper functions for reading integers and strings from the standard input
def get_int():
	sc.scan()
	i, e = int(sc.text()), None
	if e!= None:
		raise e
	return i

def get_string():
	sc.scan()
	return sc.text()

# Helper functions for basic arithmetic operations
def abs(a):
	return abs(a)

def pow(p, q):
	return pow(p, q)

def pow_mod(n, p):
	# Base case: if p is 0, return 1
	if p == 0:
		return 1
	elif p % 2 == 0:
		# Recursive case: if p is even, square the base and recursively call pow_mod
		t = pow_mod(n, p // 2)
		return calc_mod(t * t)
	else:
		# Recursive case: if p is odd, multiply the base with the result of recursively calling pow_mod with p-1
		return calc_mod(n * pow_mod(n, p - 1))

# Helper functions for finding the minimum and maximum values
def min(nums):
	# Base case: if there are no numbers, panic
	if len(nums) == 0:
		raise Exception("function min() requires at least one argument.")

	# Initialize the minimum value with the first number
	res = nums[0]

	# Iterate through all numbers and update the minimum value if necessary
	for i in range(0, len(nums)):
		res = min(res, nums[i])
	return res

def max(nums):
	# Base case: if there are no numbers, panic
	if len(nums) == 0:
		raise Exception("function max() requires at least one argument.")

	# Initialize the maximum value with the first number
	res = nums[0]

	# Iterate through all numbers and update the maximum value if necessary
	for i in range(0, len(nums)):
		res = max(res, nums[i])
	return res

# Helper function for searching a string in an array of strings
def str_search(a, b):
	# Iterate through all strings in the array and return true if the target string is found
	for i in range(0, len(a)):
		if a[i] == b:
			return True
	return False

# Helper function for printing an integer array
def print_int_array(array):
	# Convert the integer array to a string and print it without the brackets and the leading and trailing spaces
	str_array = str(array)
	print(str_array[1 : len(str_array) - 1])

# Helper function for calculating the modulo operation
def calc_mod(x):
	# Calculate the modulo of x with the modulus constant
	return x % mod

# Helper function for reversing a string
def reverse(s):
	# Create a slice of runes from the input string, reverse it in-place, and convert it back to a string
	runes = []
	for i in range(0, len(s)):
		runes.append(s[i])
	runes.reverse()
	return "".join(runes)

# Helper function for checking if a number is prime
def is_prime(n):
	# Base case: if n is less than 2, it is not prime
	if n < 2:
		return False

	# Base case: if n is 2, it is prime
	if n == 2:
		return True

	# Base case: if n is even, it is not prime
	if n % 2 == 0:
		return False

	# Calculate the square root of n and iterate through all odd numbers from 3 to the square root of n
	sqrt_n = int(math.sqrt(n))
	for i in range(3, sqrt_n + 1, 2):
		# If n is divisible by i, it is not prime
		if n % i == 0:
			return False
	# If we have reached here, n is prime
	return True

# 