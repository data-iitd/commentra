
# Go:
package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Constants for buffer sizes and modulo value
const (
	initialBufSize = 10000
	maxBufSize     = 1000000
	mod            = 1e9 + 7
)

// Scanner for reading input
var (
	sc *bufio.Scanner = func() *bufio.Scanner {
		sc := bufio.NewScanner(os.Stdin)
		buf := make([]byte, initialBufSize)
		sc.Buffer(buf, maxBufSize)
		sc.Split(bufio.ScanWords)
		return sc
	}()
)

func main() {
	// Read an integer input
	N := getInt()

	// Determine the output based on the last digit of N
	switch N % 10 {
	case 2, 4, 5, 7, 9:
		fmt.Println("hon")
	case 0, 1, 6, 8:
		fmt.Println("pon")
	case 3:
		fmt.Println("bon")
	}
}

// Graph structure to represent edges
type Graph struct {
	n     int
	edges [][]int
}

// Constructor for creating a new graph
func NewGraph(n int) *Graph {
	g := &Graph{
		n:     n,
		edges: make([][]int, n),
	}
	return g
}

// Method to add an edge between two nodes in the graph
func (g *Graph) AddEdge(u, v int) {
	g.edges[v] = append(g.edges[v], u)
	g.edges[u] = append(g.edges[u], v)
}

// Depth-first search (DFS) algorithm implementation
func dfs(c int, edges [][]int, visited map[int]struct{}) {
	visited[c] = struct{}{}

	// Visit all adjacent nodes recursively
	for _, v := range edges[c] {
		_, flag := visited[v]
		if flag {
			continue
		}
		dfs(v, edges, visited)
	}
}

// Breadth-first search (BFS) algorithm implementation
func bfs(c int, graph *Graph) {
	next := make([]int, 0)
	next = append(next, c)
	visited := make(map[int]struct{})

	// Continue until there are no more nodes to visit
	for len(next) != 0 {
		u := next[0]
		next = next[1:]
		visited[u] = struct{}{}

		// Process each adjacent node
		for _, v := range graph.edges[u] {
			_, flag := visited[v]
			if flag {
				continue
			}

			// Placeholder for processing the node (e.g., marking, counting, etc.)

			next = append(next, v)
		}
	}
}

// Function to read an integer from input
def getInt():
	sc.scan()
	i, e = strconv.atoi(sc.text())
	if e != None:
		raise e
	return i

# Function to read an array of integers from input
def getIntArray(n):
	array = [0] * n
	for i in range(n):
		array[i] = getInt()
	return array

# Function to read a string from input
def getString():
	sc.scan()
	return sc.text()

# Function to read an array of strings from input
def getStringArray(n):
	array = [0] * n
	for i in range(n):
		array[i] = getString()
	return array

# Function to calculate the absolute value of an integer
def abs(a):
	return int(math.fabs(a))

# Function to calculate p raised to the power of q
def pow(p, q):
	return int(math.pow(p, q))

# Function to calculate n raised to the power of p modulo mod
def powMod(n, p):
	if p == 0:
		return 1
	elif p % 2 == 0:
		t = powMod(n, p / 2)
		return calcMod(t * t)
	else:
		return calcMod(n * powMod(n, p - 1))

# Function to find the minimum value among a list of integers
def min(nums):
	if len(nums) == 0:
		raise Exception("function min() requires at least one argument.")
	res = nums[0]
	for i in range(len(nums)):
		res = min(res, nums[i])
	return res

# Function to find the maximum value among a list of integers
def max(nums):
	if len(nums) == 0:
		raise Exception("function max() requires at least one argument.")
	res = nums[0]
	for i in range(len(nums)):
		res = max(res, nums[i])
	return res

# Function to check if a string exists in an array of strings
def strSearch(a, b):
	for i in range(len(a)):
		if a[i] == b:
			return True
	return False

# Function to print an array of integers
def printIntArray(array):
	strArray = str(array)
	print(strArray[1 : len(strArray) - 1])

# Function to calculate x modulo mod
def calcMod(x):
	return x % mod

# Function to reverse a string
def reverse(s):
	runes = list(s)
	for i, j in enumerate(range(len(runes))):
		runes[i], runes[j] = runes[j], runes[i]
	return "".join(runes)

# Function to check if a number is prime
def isPrime(n):
	if n < 2:
		return False
	elif n == 2:
		return True
	elif n % 2 == 0:
		return False

	sqrtN = int(math.sqrt(n))
	for i in range(3, sqrtN + 1, 2):
		if n % i == 0:
			return False
	return True

# Function to check if an integer exists in a slice
def contains(s, e):
	for v in s:
		if e == v:
			return True
	return False

# Function to create a range of integers from min to max
def makeRange(min, max):
	a = [0] * (max - min + 1)
	for i in range(len(a)):
		a[i] = min + i
	return a

# Function to generate the powerset of a given slice of integers
def powerset2(nums):
	length = int(math.pow(2, len(nums)))
	result = [0] * length

	index = 0
	result[index] = []
	index += 1

	# Generate all subsets
	for n in nums:
		max = index
		for i in range(max):
			result[index] = copyAndAppend(result[i], n)
			index += 1

	return result

# Helper function to copy a slice and append a new element
def copyAndAppend(nums, n):
	dst = nums[:]
	dst.append(n)
	return dst

# Function to calculate the greatest common divisor (GCD) of two integers
def calcGcd(x, y):
	if y == 0:
		return x
	elif x >= y:
		return calcGcd(y, x % y)
	else:
		return calcGcd(x, y % x)

# Function to get all divisors of a number
def getDivisor(n):
	divisor = {}
	divisor[1] = struct{}
	if n != 1:
		divisor[n] = struct{}

	sqrt = int(math.sqrt(n))
	for i in range(2, sqrt + 1):
		if n % i == 0:
			divisor[i] = struct{}
			divisor[n / i] = struct{}

	var divisorArray []int
	for d in divisor:
		divisorArray = append(divisorArray, d)
	return divisorArray

# Custom heap type for integers
class intHeap(object):
	def __init__(self):
		self.heap = []

	# Implementing heap.Interface for intHeap
	def Len(self):
		return len(self.heap)

	def Less(self, i, j):
		return self.heap[i] > self.heap[j]

	def Swap(self, i, j):
		self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

	# Push an element onto the heap
	def Push(self, x):
		self.heap.append(x)

	# Pop an element from the heap
	def Pop(self):
		old = self.heap
		n = len(old)
		x = old[n - 1]
		self.heap = old[0 : n - 1]
		return x

# Initialize a new integer heap
def initHeap():
	ih = intHeap()
	heap.Init(ih)
	return ih

# Push an integer onto the heap
def (h *intHeap) pushHeap(n):
	heap.Push(h, n)

# Pop an integer from the heap
def (h *intHeap) popHeap():
	return heap.Pop(h)

# Function to calculate factorial modulo mod
def factMod(n):
	value = 1
	for i in range(n):
		value = calcMod(value * (n - i))
	return value

# Function to calculate combinations modulo mod
def combinationMod(n, k):
	factN = factMod(n)
	factK = factMod(k)
	factNK = factMod(n - k)
	factKR = powMod(factK, mod - 2)
	factNKR = powMod(factNK, mod - 2)
	return calcMod(factN * calcMod(factKR * factNKR))

# Function to find prime factors of a number
def primeFactors(n):
	factors = []
	i = 2
	for i * i <= n:
		r = n % i
		if r != 0:
			i += 1
		elif r == 0:
			n /= i
			factors.append(i)
	if n > 1:
		factors.append(n)
	return factors

# 