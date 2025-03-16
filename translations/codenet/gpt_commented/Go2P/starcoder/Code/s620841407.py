
# -*- coding: utf-8 -*-

# <START-OF-CODE>

MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = 1 << 60
INF_BIT60 = 1 << 60
INF_INT32 = 1 << 30
INF_BIT30 = 1 << 30
NIL = -1

WHITE = 0
GRAY = 1
BLACK = 2

# Constants for graph algorithms

# Initialization function to set up input and output
def init():
	# Set up the input reading function to read words
	global ReadString
	ReadString = newReadString(os.Stdin, bufio.ScanWords)
	# Initialize buffered output
	global stdout
	stdout = bufio.NewWriter(os.Stdout)

# Global variables for the number of nodes and edges
n, m = ReadInt2()
edges = []

def main():
	# Read edges and build the adjacency list
	for i in range(n-1):
		x, y = ReadInt2() # Read each edge
		x -= 1
		y -= 1

		e = [x, y] # Create edge
		edges.append(e) # Append edge to the list

	# Define operations for the re-rooting solver
	def f(x, y):
		return (x * y) % m # Multiplication operation

	def g(v, p):
		return v + 1 # Increment operation

	# Create a new re-rooting solver instance
	s = NewReRootingSolver(n, edges, 1, f, g)
	# Query results for each node and print them
	for i in range(n):
		print(s.Query(i) - 1) # Output the result for each node

# Type definition for generic operations
class T:
	def __init__(self, v):
		self.v = v

	def __add__(self, other):
		return T(self.v + other.v)

	def __mul__(self, other):
		return T(self.v * other.v)

	def __str__(self):
		return str(self.v)

# Structure for the re-rooting solver
class ReRootingSolver:
	def __init__(self, nodeCount, edges, identity, operate, operateNode):
		self.NodeCount = nodeCount
		self.Adjacents = []
		self.IndexForAdjacents = []
		self.Res = []
		self.DP = []

		self.Identity = identity
		self.Operate = operate
		self.OperateNode = operateNode

		# Initialize adjacency lists
		self.Adjacents = [[] for _ in range(nodeCount)]
		self.IndexForAdjacents = [[] for _ in range(nodeCount)]
		for e in edges:
			# Build adjacency list and index mapping
			self.IndexForAdjacents[e[0]] = self.IndexForAdjacents[e[0]] + [len(self.Adjacents[e[1]])]
			self.IndexForAdjacents[e[1]] = self.IndexForAdjacents[e[1]] + [len(self.Adjacents[e[0]])]
			self.Adjacents[e[0]] = self.Adjacents[e[0]] + [e[1]]
			self.Adjacents[e[1]] = self.Adjacents[e[1]] + [e[0]]

		# Initialize DP and result arrays
		self.DP = [[] for _ in range(len(self.Adjacents))]
		self.Res = [[] for _ in range(len(self.Adjacents))]

		for i in range(len(self.Adjacents)):
			self.DP[i] = [[] for _ in range(len(self.Adjacents[i]))] # Allocate DP table

		# Initialize the solver if there are more than one node
		if self.NodeCount > 1:
			self.Initialize()
		else:
			# Base case for a single node
			self.Res[0] = self.OperateNode(self.Identity, 0)

	def Query(self, node):
		return self.Res[node] # Return the result for the queried node

	def Initialize(self):
		parents, order = [0] * self.NodeCount, [0] * self.NodeCount

		# Depth-first search to establish parent-child relationships and order of nodes
		index = 0
		stack = []
		stack = stack + [0] # Start from the root node
		parents[0] = -1 # Root has no parent
		for len(stack) > 0:
			node = stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			order[index] = node # Record the order of nodes
			index += 1
			for i in range(len(self.Adjacents[node])):
				adjacent = self.Adjacents[node][i]
				if adjacent == parents[node]:
					continue # Skip the parent node
				stack = stack + [adjacent] # Add child to the stack
				parents[adjacent] = node # Set parent

		# Process nodes from leaves to root
		for i in range(len(order) - 1, 0, -1):
			node = order[i]
			parent = parents[node]

			accum = self.Identity # Initialize accumulator
			parentIndex = -1
			for j in range(len(self.Adjacents[node])):
				if self.Adjacents[node][j] == parent:
					parentIndex = j # Find index of parent
					continue
				accum = self.Operate(accum, self.DP[node][j]) # Accumulate results from children
			self.DP[parent][self.IndexForAdjacents[node][parentIndex]] = self.OperateNode(accum, node) # Update DP for parent

		# Process nodes from root to leaves
		for i in range(len(order)):
			node = order[i]
			accum = self.Identity # Initialize accumulator
			accumsFromTail = [self.Identity] * len(self.Adjacents[node])
			accumsFromTail[len(accumsFromTail)-1] = self.Identity # Initialize tail accumulator
			for j in range(len(accumsFromTail) - 1, 0, -1):
				accumsFromTail[j-1] = self.Operate(self.DP[node][j], accumsFromTail[j]) # Accumulate results from tail
			for j in range(len(accumsFromTail)):
				# Update DP for adjacent nodes
				self.DP[self.Adjacents[node][j]][self.IndexForAdjacents[node][j]] = self.OperateNode(self.Operate(accum, accumsFromTail[j]), node)
				accum = self.Operate(accum, self.DP[node][j]) # Update accumulator
			self.Res[node] = self.OperateNode(accum, node) # Store result for the node

# Constructor for ReRootingSolver
def NewReRootingSolver(nodeCount, edges, identity, operate, operateNode):
	s = ReRootingSolver(nodeCount, edges, identity, operate, operateNode)

	# Initialize the solver if there are more than one node
	if s.NodeCount > 1:
		s.Initialize()
	else:
		# Base case for a single node
		s.Res[0] = s.OperateNode(s.Identity, 0)

	return s

# Query function to get the result for a specific node
def Query(s, node):
	return s.Query(node) # Return the result for the queried node

# Read the number of nodes and edges
n, m = ReadInt2()
# Read edges and build the adjacency list
for i in range(n-1):
	x, y = ReadInt2() # Read each edge
	x -= 1
	y -= 1

	e = [x, y] # Create edge
	edges.append(e) # Append edge to the list

# Define operations for the re-rooting solver
def f(x, y):
	return (x * y) % m # Multiplication operation

def g(v, p):
	return v + 1 # Increment operation

# Create a new re-rooting solver instance
s = NewReRootingSolver(n, edges, 1, f, g)
# Query results for each node and print them
for i in range(n):
	print(s.Query(i) - 1) # Output the result for each node

# 