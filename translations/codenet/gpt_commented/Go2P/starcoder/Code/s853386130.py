import sys
import math

# <START-OF-CODE>

mod = 1000000007
INF = 1000000007

def main():
	# Initialize a buffered reader to read input
	r = sys.stdin
	var n, m, R int
	
	# Read the number of nodes (n), edges (m), and the number of required nodes (R)
	n, m, R = map(int, r.readline().split())

	# Read the required nodes and adjust for 0-based indexing
	rs = [int(x) - 1 for x in r.readline().split()]

	# Initialize the cost matrix with INF values
	costs = [[INF] * n for i in range(n)]
	for i in range(n):
		costs[i][i] = 0 # The cost to reach itself is 0
	
	# Read the edges and their costs
	for i in range(m):
		a, b, c = map(int, r.readline().split())
		a -= 1
		b -= 1
		costs[a][b] = c # Set cost for edge a to b
		costs[b][a] = c # Set cost for edge b to a (undirected graph)

	# Calculate the shortest paths using the Floyd-Warshall algorithm
	for k in range(n):
		for i in range(n):
			for j in range(n):
				costs[i][j] = min(costs[i][j], costs[i][k]+costs[k][j])

	# Generate all permutations of the required nodes
	perms = permutations(rs)
	ans = INF
	
	# Evaluate each permutation to find the minimum cost path
	for perm in perms:
		tmp = 0
		for j in range(1, len(perm)):
			from_ = perm[j-1]
			to_ = perm[j]
			tmp += costs[from_][to_] # Accumulate the cost of the current permutation
		ans = min(ans, tmp) # Update the answer with the minimum cost found
	
	# Output the minimum cost
	print(ans)

# permutations generates all permutations of an array
def permutations(arr):
	res = []
	helper(arr, 0, res)
	return res

# Recursive helper function to generate permutations
def helper(arr, n, res):
	if n == len(arr):
		tmp = [0] * len(arr)
		copy(tmp, arr)
		res.append(tmp)
	else:
		for i in range(n, len(arr)):
			helper(arr, n+1, res)
			# Swap elements based on the parity of n
			if n%2 == 1:
				tmp = arr[i]
				arr[i] = arr[n]
				arr[n] = tmp
			else:
				tmp = arr[0]
				arr[0] = arr[n]
				arr[n] = tmp
	return res

# Union-Find structure for disjoint set operations
class unionFind:
	def __init__(self, n):
		self.d = [-1] * n
	def find(self, x):
		if self.d[x] < 0:
			return x
		self.d[x] = self.find(self.d[x]) # Path compression
		return self.d[x]
	def unite(self, x, y):
		rootX = self.find(x)
		rootY = self.find(y)
		if rootX == rootY:
			return False # x and y are already in the same set
		# Union by size
		if self.d[rootX] < self.d[rootY]:
			self.d[rootX] += self.d[rootY]
			self.d[rootY] = rootX
		else:
			self.d[rootY] += self.d[rootX]
			self.d[rootX] = rootY
		return True
	def same(self, x, y):
		return self.find(x) == self.find(y)
	def size(self, x):
		return -self.d[self.find(x)]

# Utility functions

# min returns the smaller of two integers
def min(x, y):
	if x < y:
		return x
	return y

# max returns the larger of two integers
def max(x, y):
	if x > y:
		return x
	return y

# abs returns the absolute value of an integer
def abs(x):
	if x < 0:
		return -x
	return x

# primeFactor returns the prime factorization of x
def primeFactor(x):
	res = {}
	for i in range(2, int(math.sqrt(x)) + 1):
		for j in range(2, int(x/i) + 1):
			if x%i == 0:
				if i in res:
					res[i] += 1
				else:
					res[i] = 1
				x = x / i
	if x!= 1:
		res[x] = 1
	return res

# divisor returns all divisors of x
def divisor(x):
	res = []
	for i in range(1, int(math.sqrt(x)) + 1):
		if x%i == 0:
			res.append(i)
			if i!= x/i:
				res.append(x/i)
	return res

# gcd returns the greatest common divisor of x and y
def gcd(x, y):
	if y == 0:
		return x
	return gcd(y, x%y)

# lcm returns the least common multiple of x and y
def lcm(x, y):
	return x / gcd(x, y) * y

# reverseString returns the reversed version of a string
def reverseString(s):
	r = []
	for i in range(len(s)):
		r.append(s[len(s) - i - 1])
	return ''.join(r)

# pow calculates a raised to the power of n
def pow(a, n):
	ret = 1
	for i in range(1, n + 1):
		ret *= a
	return ret

# Queue structure for implementing a queue
class Queue:
	def __init__(self):
		self.q = []
	def empty(self):
		return len(self.q) == 0
	def push(self, i):
		self.q.append(i)
	def pop(self):
		if self.empty():
			return 0, False
		else:
			res = self.q[0]
			self.q = self.q[1:]
			return res, True

# Stack structure for implementing a stack
class Stack:
	def __init__(self):
		self.s = []
	def empty(self):
		return len(self.s) == 0
	def push(self, i):
		self.s.append(i)
	def pop(self):
		if self.empty():
			return 0, False
		else:
			index = len(self.s) - 1
			res = self.s[index]
			self.s = self.s[:index]
			return res, True

# priority_queue structure for implementing a max-heap
class intHeap:
	def __init__(self):
		self.h = []
	def Len(self):
		return len(self.h)
	def Less(self, i, j):
		return self.h[i] > self.h[j] # Max-heap
	def Swap(self, i, j):
		self.h[i], self.h[j] = self.h[j], self.h[i]
	def Push(self, x):
		self.h.append(x)
	def Pop(self):
		old = self.h
		n = len(old)
		x = old[n-1]
		self.h = old[0 : n-1]
		return x

# sortable points structure for sorting points
class point:
	def __init__(self, x, y):
		self.x = x
		self.y = y
	def __repr__(self):
		return "(" + str(self.x) + ", " + str(self.y) + ")"

# points structure for sorting points
class points:
	def __init__(self, p):
		self.p = p
	def Len(self):
		return len(self.p)
	def Less(self, i, j):
		return self.p[i].x < self.p[j].x
	def Swap(self, i, j):
		self.p[i], self.p[j] = self.p[j], self.p[i]

# 