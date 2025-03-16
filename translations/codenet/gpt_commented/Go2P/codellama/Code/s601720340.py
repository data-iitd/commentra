
# Go:
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"

	"flag"
	"runtime"
	"runtime/pprof"
)

// Define a large prime number for modulo operations
var magic = 1000000007

// Command-line flags for CPU and memory profiling
var cpuprofile = flag.String("cpuprofile", "", "write cpu profile to file")
var memprofile = flag.String("memprofile", "", "write mem profile to file")

var N int
var p [200000]int

// Function to check if a number exists in the array p
func find(n int) int {
	for i := 0; i < N; i++ {
		if n == p[i] {
			return 0 // Number found
		}
	}
	return 1 // Number not found
}

// Main solving function
func solve() {
	io := NewIo() // Create a new IO instance for input/output
	defer io.Flush() // Ensure the output buffer is flushed at the end

	// PARSE HELPER SESSION
	// Read and log the input values
	X := io.NextInt() // Read an integer
	Logf("%v\n", X) // Log the integer
	N = io.NextInt() // Read the size of the array
	Logf("%v\n", N) // Log the size
	for i := 0; i < N; i++ {
		p[i] = io.NextInt() // Read integers into the array p
	}
	Logf("p %v\n", p[0:10]) // Log the first 10 elements of p

	// Check for numbers around X that are not in the array p
	for i := 0; i <= 100; i++ {
		if find(X-i) == 1: # Check X - i
			print(X-i) # Print the result
			exit(0) # Exit the program
		if find(X+i) == 1: # Check X + i
			print(X+i) # Print the result
			exit(0) # Exit the program
	}

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
	# 	Logf("%v -> %v\n", p, n)
	# 	dp[n] = p
	# }, func(n, p int) {
	# 	Logf("%v -> %v\n", n, p)
	# })
	# Logf("%v\n", dp[0:5])

	# COMBINATION
	# fmt.Printf("%d %d %d\n", N, M, intMax(N, M))
	# fmt.Printf("Lucas %d %d\n", combMod(N, M, 13), combination(N, M))
}

# Main function to execute the program
def main():
	flag.Parse() # Parse command-line flags
	if *cpuprofile != "":
		f = open(*cpuprofile, "w") # Create CPU profile file
		pprof.StartCPUProfile(f) # Start CPU profiling
		defer pprof.StopCPUProfile() # Stop profiling when done
	if *memprofile != "":
		f = open(*memprofile, "w") # Create memory profile file
		runtime.GC() # Trigger garbage collection for accurate memory stats
		pprof.WriteHeapProfile(f) # Write memory profile
		f.close()
	solve() # Call the solve function

# Libraries

# Io helps parsing inputs from standard input for programming contests.
class Io:
	def __init__(self):
		self.reader = bufio.Reader(sys.stdin) # Initialize reader
		self.writer = bufio.Writer(sys.stdout) # Initialize writer
		self.tokens = []
		self.nextToken = 0

	# Flush flushes buffer. Don't forget to do this when you call Io.Printf/Io.PrintLn for final output.
	def Flush(self):
		self.writer.flush() # Flush the writer buffer

	# NextLine parses line as string.
	def NextLine(self):
		buffer = []
		while True:
			line, isPrefix, err = self.reader.readLine() # Read a line
			if err:
				panic(err) # Panic on error
			buffer += line # Append line to buffer
			if not isPrefix:
				break # Break if not a prefix
		return "".join(buffer) # Return the complete line as string

	# Next parse next word as string.
	def Next(self):
		while self.nextToken >= len(self.tokens):
			line = self.NextLine() # Read the next line
			self.tokens = line.split() # Split line into tokens
			self.nextToken = 0 # Reset token index
		r = self.tokens[self.nextToken] # Get the next token
		self.nextToken += 1 # Move to the next token
		return r # Return the token

	# NextInt parse next word as Int.
	def NextInt(self):
		i, err = strconv.Atoi(self.Next()) # Convert the next token to int
		if err:
			panic(err) # Panic on error
		return i # Return the integer

	# NextFloat parses next word as float64.
	def NextFloat(self):
		i, err = strconv.ParseFloat(self.Next(), 64) # Convert the next token to float64
		if err:
			panic(err) # Panic on error
		return i # Return the float

	# PrintLn does buffer write with linefeed.
	def PrintLn(self, a):
		self.writer.write(a + "\n") # Write to buffer with linefeed

	# Printf does formatted buffer write.
	def Printf(self, format, a):
		self.writer.write(format % a) # Write formatted output to buffer

	# PrintIntLn prints Int array in a single line.
	def PrintIntLn(self, a):
		b = []
		for x in a:
			b += [x] # Append each integer to the slice
		self.PrintLn(b) # Print the integers in a single line

	# PrintStringLn prints string array in a single line.
	def PrintStringLn(self, a):
		b = []
		for x in a:
			b += [x] # Append each string to the slice
		self.PrintLn(b) # Print the strings in a single line

	# Log print single value to standard output (contest server ignores this so you don't have to remove when finishing)
	def Log(name, value):
		print(name + "=" + str(value), file=sys.stderr) # Log the value to stderr

	# Logf print formatted output to standard output (contest server ignores this so you don't have to remove when finishing)
	def Logf(format, a):
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
			for i in range(1, m + 1):
				res /= i # Calculate denominator
			return res # Return the combination result

	# Calculate combination modulo based on Lucas theorem
	def combMod(n, m, p):
		return lucas(n, m, p) # Call lucas function

	# Breadth-First Search (BFS) implementation
	def bfs(start, nodes, fn):
		frontier = [start] # Initialize the frontier with the start node
		visited = {} # Track visited nodes

		while frontier:
			next = [] # Prepare for the next frontier
			for node in frontier:
				visited[node] = True # Mark the node as visited
				fn(node) # Execute the provided function on the node
				for n in bfsFrontier(node, nodes, visited):
					next += [n] # Add unvisited neighbors to the next frontier
			frontier = next # Move to the next frontier

	# Helper function to get unvisited neighbors for BFS
	def bfsFrontier(node, nodes, visited):
		next = []
		iter = lambda n: not visited.get(n) # Check if a node is unvisited
		for n in nodes[node]:
			if iter(n):
				next += [n] # Add unvisited neighbor to the list
		return next # Return the list of unvisited neighbors

	# Depth-First Search (DFS) implementation
	def dfs(node, nodes, fn):
		dfsRecur(node, nodes, {}, fn) # Start the recursive DFS

	# Recursive DFS helper function
	def dfsRecur(node, nodes, v, fn):
		v[node] = True # Mark the node as visited
		fn(node) # Execute the provided function on the node
		for n in nodes[node]:
			if not v.get(n):
				dfsRecur(n, nodes, v, fn) # Recursively visit unvisited neighbors

	# DFS with two functions: one before entering child tree, and another after
	def dfs2(node, nodes, fn1, fn2):
		dfs2Recur(node, -1, nodes, {}, fn1, fn2) # Start the recursive DFS with parent tracking

	# Recursive DFS helper function with parent tracking
	def dfs2Recur(node, parent, nodes, v, fn1, fn2):
		v[node] = True # Mark the node as visited
		if fn1:
			fn1(node, parent) # Execute the first function
		for n in nodes[node]:
			if not v.get(n):
				dfs2Recur(n, node, nodes, v, fn1, fn2) # Recursively visit unvisited neighbors
		if fn2:
			fn2(node, parent) # Execute the second function

	# Stack data structure implementation
	class Stack:
		def __init__(self):
			self.top = None # Pointer to the top element
			self.size = 0 # Size of the stack

		# Len returns stack height
		def Len(self):
			return self.size # Return the size of the stack

		# Push puts an element on the stack.
		def Push(self, value):
			self.top = Element(value, self.top) # Create a new element and set it as the top
			self.size += 1 # Increment the size

		# Pop picks out the last element from the stack.
		def Pop(self):
			if self.size > 0:
				value, self.top = self.top.value, self.top.next # Get the top value and update the top pointer
				self.size -= 1 # Decrement the size
				return value # Return the value
			return None # Return None if the stack is empty

		# Element is a struct for stack element
		class Element:
		