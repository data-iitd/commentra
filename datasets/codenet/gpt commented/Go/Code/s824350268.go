package main

import (
	"bufio"
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

// Main function
func main() {
	// Read an integer N from input
	N := getInt()
	// Calculate the integer square root of N
	sqrtN := int(math.Sqrt(float64(N)))

	// Initialize min to N, which will hold the minimum value found
	min := N
	// Iterate through all possible divisors of N
	for i := 1; i <= sqrtN; i++ {
		// If i is not a divisor of N, skip to the next iteration
		if N % i != 0 {
			continue
		}

		// Calculate the value based on the divisor and its complement
		num := i + (N/i) - 2
		// Update min if the new value is smaller
		if num < min {
			min = num
		}
	}

	// Print the minimum value found
	fmt.Println(min)
}

// Graph structure to represent a graph with n nodes
type Graph struct {
	n     int
	edges [][]int
}

// NewGraph creates a new graph with n nodes
func NewGraph(n int) *Graph {
	g := &Graph{
		n:     n,
		edges: make([][]int, n),
	}
	return g
}

// AddEdge adds an undirected edge between nodes u and v
func (g *Graph) AddEdge(u, v int) {
	g.edges[v] = append(g.edges[v], u)
	g.edges[u] = append(g.edges[u], v)
}

// Depth-first search (DFS) algorithm to traverse the graph
func dfs(c int, edges [][]int, visited map[int]struct{}) {
	// Mark the current node as visited
	visited[c] = struct{}{}

	// Recursively visit all adjacent nodes
	for _, v := range edges[c] {
		_, flag := visited[v]
		if flag {
			continue
		}
		dfs(v, edges, visited)
	}
}

// Helper function to read an integer from input
func getInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

// Helper function to read a string from input
func getString() string {
	sc.Scan()
	return sc.Text()
}

// Function to return the absolute value of an integer
func abs(a int) int {
	return int(math.Abs(float64(a)))
}

// Function to compute p raised to the power of q
func pow(p, q int) int {
	return int(math.Pow(float64(p), float64(q)))
}

// Function to compute (n^p) % mod using exponentiation by squaring
func powMod(n, p int) int {
	if p == 0 {
		return 1
	} else if p%2 == 0 {
		t := powMod(n, p/2)
		return calcMod(t * t)
	} else {
		return calcMod(n * powMod(n, p-1))
	}
}

// Function to find the minimum value among a variable number of integers
func min(nums ...int) int {
	if len(nums) == 0 {
		panic("function min() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Min(float64(res), float64(nums[i])))
	}
	return res
}

// Function to find the maximum value among a variable number of integers
func max(nums ...int) int {
	if len(nums) == 0 {
		panic("function max() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Max(float64(res), float64(nums[i])))
	}
	return res
}

// Function to check if a string exists in a slice of strings
func strSearch(a []string, b string) bool {
	for i := 0; i < len(a); i++ {
		if a[i] == b {
			return true
		}
	}
	return false
}

// Function to print an integer array in a formatted way
func printIntArray(array []int) {
	strArray := fmt.Sprint(array)
	fmt.Println(strArray[1 : len(strArray)-1])
}

// Function to calculate x % mod
func calcMod(x int) int {
	return x % mod
}

// Function to reverse a string
func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// Function to check if a number is prime
func isPrime(n int) bool {
	if n < 2 {
		return false
	} else if n == 2 {
		return true
	} else if n % 2 == 0 {
		return false
	}

	// Check for factors from 3 to the square root of n
	sqrtN := int(math.Sqrt(float64(n)))
	for i := 3; i <= sqrtN; i += 2 {
		if n % i == 0 {
			return false
		}
	}

	return true
}
