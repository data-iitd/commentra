package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Constants definition
const (
	initialBufSize = 10000
	maxBufSize     = 1000000
	mod            = 1e9 + 7
)

// Variables definition and initialization
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
	// Read the first integer from the standard input
	N := getInt()

	// Calculate the square root of N
	sqrtN := int(math.Sqrt(float64(N)))

	// Initialize the minimum number with N
	min := N

	// Iterate through all numbers from 1 to the square root of N
	for i := 1; i <= sqrtN; i++ {
		// Check if N is divisible by i
		if N % i != 0 {
			continue
		}

		// Calculate the number of divisors of i and N
		num := i + (N / i) - 2

		// Update the minimum number if the current number is smaller
		if num < min {
			min = num
		}
	}

	// Print the minimum number
	fmt.Println(min)
}

// Define a Graph data structure
type Graph struct {
	n     int
	edges [][]int
}

// Initialize a new Graph with n vertices
func NewGraph(n int) *Graph {
	g := &Graph{
		n:     n,
		edges: make([][]int, n),
	}
	return g
}

// Add an edge between two vertices in the Graph
func (g *Graph) AddEdge(u, v int) {
	g.edges[v] = append(g.edges[v], u)
	g.edges[u] = append(g.edges[u], v)
}

// Depth First Search function
func dfs(c int, edges [][]int, visited map[int]struct{}) {
	// Mark the current vertex as visited
	visited[c] = struct{}{}

	// Iterate through all neighbors of the current vertex
	for _, v := range edges[c] {
		// If the neighbor is already visited, skip it
		_, flag := visited[v]
		if flag {
			continue
		}

		// Recursively call DFS for the neighbor
		dfs(v, edges, visited)
	}
}

// Helper functions for reading integers and strings from the standard input
func getInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func getString() string {
	sc.Scan()
	return sc.Text()
}

// Helper functions for basic arithmetic operations
func abs(a int) int {
	return int(math.Abs(float64(a)))
}

func pow(p, q int) int {
	return int(math.Pow(float64(p), float64(q)))
}

func powMod(n, p int) int {
	// Base case: if p is 0, return 1
	if p == 0 {
		return 1
	} else if p%2 == 0 {
		// Recursive case: if p is even, square the base and recursively call powMod
		t := powMod(n, p/2)
		return calcMod(t * t)
	} else {
		// Recursive case: if p is odd, multiply the base with the result of recursively calling powMod with p-1
		return calcMod(n * powMod(n, p-1))
	}
}

// Helper functions for finding the minimum and maximum values
func min(nums ...int) int {
	// Base case: if there are no numbers, panic
	if len(nums) == 0 {
		panic("funciton min() requires at least one argument.")
	}

	// Initialize the minimum value with the first number
	res := nums[0]

	// Iterate through all numbers and update the minimum value if necessary
	for i := 0; i < len(nums); i++ {
		res = int(math.Min(float64(res), float64(nums[i])))
	}

	// Return the minimum value
	return res
}

func max(nums ...int) int {
	// Base case: if there are no numbers, panic
	if len(nums) == 0 {
		panic("funciton max() requires at least one argument.")
	}

	// Initialize the maximum value with the first number
	res := nums[0]

	// Iterate through all numbers and update the maximum value if necessary
	for i := 0; i < len(nums); i++ {
		res = int(math.Max(float64(res), float64(nums[i])))
	}

	// Return the maximum value
	return res
}

// Helper function for searching a string in an array of strings
func strSearch(a []string, b string) bool {
	// Iterate through all strings in the array and return true if the target string is found
	for i := 0; i < len(a); i++ {
		if a[i] == b {
			return true
		}
	}

	// If the target string is not found, return false
	return false
}

// Helper function for printing an integer array
func printIntArray(array []int) {
	// Convert the integer array to a string and print it without the brackets and the leading and trailing spaces
	strArray := fmt.Sprint(array)
	fmt.Println(strArray[1 : len(strArray)-1])
}

// Helper function for calculating the modulo operation
func calcMod(x int) int {
	// Calculate the modulo of x with the modulus constant
	return x % mod
}

// Helper function for reversing a string
func reverse(s string) string {
	// Create a slice of runes from the input string, reverse it in-place, and convert it back to a string
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// Helper function for checking if a number is prime
func isPrime(n int) bool {
	// Base case: if n is less than 2, it is not prime
	if n < 2 {
		return false
	}

	// Base case: if n is 2, it is prime
	if n == 2 {
		return true
	}

	// Base case: if n is even, it is not prime
	if n % 2 == 0 {
		return false
	}

	// Calculate the square root of n and iterate through all odd numbers from 3 to the square root of n
	sqrtN := int(math.Sqrt(float64(n)))
	for i := 3; i <= sqrtN; i += 2 {
		// If n is divisible by i, it is not prime
		if n % i == 0 {
			return false
		}
	}

	// If we have reached here, n is prime
	return true
}