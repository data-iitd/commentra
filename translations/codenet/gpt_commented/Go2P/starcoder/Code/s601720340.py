import sys

# Define a large prime number for modulo operations
magic = 1000000007

# Command-line flags for CPU and memory profiling
cpuprofile = ""
memprofile = ""

# Function to check if a number exists in the array p
def find(n):
	for i in range(N):
		if n == p[i]:
			return 0 # Number found
	return 1 # Number not found

# Main solving function
def solve():
	# PARSE HELPER SESSION
	# Read and log the input values
	X = int(sys.stdin.readline()) # Read an integer
	print(X) # Log the integer
	N = int(sys.stdin.readline()) # Read the size of the array
	print(N) # Log the size
	for i in range(N):
		p[i] = int(sys.stdin.readline()) # Read integers into the array p
	print("p", p[0:10]) # Log the first 10 elements of p

	# Check for numbers around X that are not in the array p
	for i in range(101):
		if find(X-i) == 1: # Check X - i
			print(X-i) # Print the result
			return
		if find(X+i) == 1: # Check X + i
			print(X+i) # Print the result
			return

	# OUTPUT GENERATION PART
	# ans := 0
	# print(ans)

	# if ans > 0:
	#   print("Yes")
	# else:
	#   print("No")

	# BFS/DFS PART
	# visited := []int{}
	# bfs/dfs(1, neighbor, func(node int) {
	# 	visited = append(visited, node)
	# })
	# print(visited)

	# DFS 2
	# var dp [2000000]int
	# nei := make(map[int][]int)
	# nei[0] = []int{1, 2}
	# nei[1] = []int{0}
	# nei[2] = []int{0, 3}
	# nei[3] = []int{2}
	# dfs2(0, nei, func(n, p int) {
	# 	print(p, "->", n)
	# 	dp[n] = p
	# }, func(n, p int) {
	# 	print(n, "->", p)
	# })
	# print(dp[0:5])

	# COMBINATION
	# print(N, M, max(N, M))
	# print("Lucas", combMod(N, M, 13), combination(N, M))

# Main function to execute the program
def main():
	global cpuprofile, memprofile
	if cpuprofile!= "":
		f = open(cpuprofile, "w") # Create CPU profile file
		p = pstats.Stats(f) # Create a new profiler
		p.strip_dirs().sort_stats("time").print_stats() # Print CPU profile to file
		f.close() # Close the file when done
	if memprofile!= "":
		f = open(memprofile, "w") # Create memory profile file
		p = pstats.Stats(f) # Create a new profiler
		p.strip_dirs().sort_stats("time").print_stats() # Print memory profile to file
		f.close() # Close the file when done
	solve() # Call the solve function

# Libraries

# Io helps parsing inputs from standard input for programming contests.
class Io:
	def __init__(self):
		self.reader = sys.stdin # Initialize reader
		self.writer = sys.stdout # Initialize writer
	def Flush(self):
		pass # Do nothing
	def NextLine(self):
		return self.reader.readline() # Read a line
	def Next(self):
		return self.reader.readline().strip() # Read a line and strip whitespace
	def NextInt(self):
		return int(self.Next()) # Read a line and convert to integer
	def NextFloat(self):
		return float(self.Next()) # Read a line and convert to float
	def PrintLn(self, a):
		print(a, file=self.writer) # Write to buffer with linefeed
	def Printf(self, format, a):
		print(format % a, file=self.writer) # Write formatted output to buffer
	def PrintIntLn(self, a):
		print(*a, file=self.writer) # Write integers in a single line
	def PrintStringLn(self, a):
		print(*a, file=self.writer) # Write strings in a single line
	def Log(self, name, value):
		print("%s=%+v" % (name, value), file=sys.stderr) # Log the value to stderr
	def Logf(self, format, a):
		print(format % a, file=sys.stderr) # Log formatted output to stderr

# Helper functions for mathematical operations

# Returns the minimum of two integers
def intMin(a, b):
	if a < b:
		return a
	return b

# Returns the maximum of two integers
def intMax(a, b):
	if a > b:
		return a
	return b

# Direct calculation of combination
# n, m should be "small"
def combination(n, m):
	if m > n:
		return 0 # Not possible to choose more than available
	elif m == n or m == 0:
		return 1 # Only one way to choose all or none
	else:
		res = 1
		for i in range(m):
			res *= (n - i) # Calculate numerator
		for i in range(1, m+1):
			res /= i # Calculate denominator
		return res # Return the combination result

# Calculate combination modulo based on Lucas theorem
def lucas(n, m, p):
	ntemp = n
	mtemp = m
	res = 1
	for i in range(100):
		nreminder = ntemp % p # Remainder of n
		ntemp = ntemp / p # Update n
		mreminder = mtemp % p # Remainder of m
		mtemp = mtemp / p # Update m
		res = res * (combination(nreminder, mreminder) % p) # Combine results
		if ntemp == 0:
			break # Break if n is exhausted
	return res % p # Return the result modulo p

# Wrapper function for combination modulo
def combMod(n, m, p):
	return lucas(n, m, p) # Call lucas function

# Breadth-First Search (BFS) implementation
def bfs(start, nodes, fn):
	frontier = [start] # Initialize the frontier with the start node
	visited = {} # Track visited nodes

	for 0 < len(frontier):
		next = [] # Prepare for the next frontier
		for node in frontier:
			visited[node] = True # Mark the node as visited
			fn(node) # Execute the provided function on the node
			for n in bfsFrontier(node, nodes, visited):
				next = append(next, n) # Add unvisited neighbors to the next frontier
		frontier = next # Move to the next frontier

# Helper function to get unvisited neighbors for BFS
def bfsFrontier(node, nodes, visited):
	next = []
	iter = lambda n: not visited[n] # Check if a node is unvisited
	for n in nodes[node]:
		if iter(n):
			next = append(next, n) # Add unvisited neighbor to the list
	return next # Return the list of unvisited neighbors

# Depth-First Search (DFS) implementation
def dfs(node, nodes, fn):
	dfsRecur(node, nodes, {}, fn) # Start the recursive DFS

# Recursive DFS helper function
def dfsRecur(node, nodes, v, fn):
	v[node] = True # Mark the node as visited
	fn(node) # Execute the provided function on the node
	for n in nodes[node]:
		if not v[n]:
			dfsRecur(n, nodes, v, fn) # Recursively visit unvisited neighbors

# DFS with two functions: one before entering child tree, and another after
def dfs2(node, nodes, fn1, fn2):
	dfs2Recur(node, -1, nodes, {}, fn1, fn2) # Start the recursive DFS with parent tracking

# Recursive DFS helper function with parent tracking
def dfs2Recur(node, parent, nodes, v, fn1, fn2):
	v[node] = True # Mark the node as visited
	if fn1!= None:
		fn1(node, parent) # Execute the first function
	for n in nodes[node]:
		if not v[n]:
			dfs2Recur(n, node, nodes, v, fn1, fn2) # Recursively visit unvisited neighbors
	if fn2!= None:
		fn2(node, parent) # Execute the second function

# Stack data structure implementation
class Stack:
	def __init__(self):
		self.top = None # Pointer to the top element
		self.size = 0 # Size of the stack
	def Len(self):
		return self.size # Return the size of the stack
	def Push(self, value):
		self.top = Element(value, self.top) # Create a new element and set it as the top
		self.size += 1 # Increment the size
	def Pop(self):
		if self.size > 0:
			value, self.top = self.top.value, self.top.next # Get the top value and update the top pointer
			self.size -= 1 # Decrement the size
			return value
		return None # Return nil if the stack is empty

# Element is a struct for stack element
class Element:
	def __init__(self, value, next):
		self.value = value # Value of the element
		self.next = next # Pointer to the next element

# Power function for integer parameters
def powerInt(n, p):
	tmp = 1
	for i in range(n):
		tmp *= p # Calculate p^n
	return tmp # Return the result

# Function to find divisors of a number
def findDivisors(n, a):
	if n == 1:
		return # 1 has no divisors
	sqrt = int(math.sqrt(float(n))) # Calculate the square root of n
	for i in range(2, sqrt+1):
		if n%i == 0:
			a.append(i) # Append divisor i
			a.append(n/i) # Append corresponding divisor n/i
	a.append(n) # Append n itself as a divisor

# Function to remove duplicates from a slice
def removeDuplicate(a):
	m = {} # Create a map to track unique values
	for i in range(len(a)):
		m[a[i]] = True # Mark each value as seen
	res = []
	for i in m:
		res.append(i) # Append unique values to the result slice
	return res # Return the slice of unique values

# Function to calculate the absolute value
def abs(a):
	if a > 0:
		return a # Return a if positive
	return -a # Return -a if negative

# Function to calculate the greatest common divisor (GCD)
def gcd(a, b):
	for a!= 0:
		a, b = b % a, a # Euclidean algorithm
	return b # Return the GCD

# Function to calculate power of 2 modulo a given number
def power2mod(n, mod):
	res, x = 1, 2
	for ; n > 0; n >>= 1:
		if n&1 == 1:
			res = res * x % mod # Update result if the current bit is set
		x = x * x % mod # Square the base
	return res # Return the result

# Function to calculate power of 2 with modulo magic
def power2(n):
	return power2mod(n, magic) # Call power2mod with magic

# Main execution
if __name__ == "__main__":
	global cpuprofile, memprofile
	if cpuprofile!= "":
		f = open(cpuprofile, "w") # Create CPU profile file
		p = pstats.Stats(f) # Create a new profiler
		p.strip_dirs().sort_stats("time").print_stats() # Print CPU profile to file
		f.close() # Close the file when done
	if memprofile!= "":
		f = open(memprofile, "w") # Create memory profile file
		p = pstats.Stats(f) # Create a new profiler
		p.strip_dirs().sort_stats("time").print_stats() # Print memory profile to file
		f.close() # Close the file when done
	solve() # Call the solve function

