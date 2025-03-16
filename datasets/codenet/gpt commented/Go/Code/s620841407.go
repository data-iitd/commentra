/*
URL:
https://atcoder.jp/contests/dp/tasks/dp_v
*/

package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)

/********** FAU standard libraries **********/

// Example of binary expression formatting
// fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

// Example of input reading functions
// str := ReadString()
// i := ReadInt()
// X := ReadIntSlice(n)
// S := ReadRuneSlice()
// a := ReadFloat64()
// A := ReadFloat64Slice(n)

// Example of output formatting functions
// str := ZeroPaddingRuneSlice(num, 32)
// str := PrintIntsLine(X...)

/*******************************************************************/

// Constants for general purpose usage
const (
	MOD          = 1000000000 + 7 // Modulus for calculations
	ALPHABET_NUM = 26              // Number of letters in the alphabet
	INF_INT64    = math.MaxInt64   // Maximum value for int64
	INF_BIT60    = 1 << 60         // Large value for bit manipulation
	INF_INT32    = math.MaxInt32    // Maximum value for int32
	INF_BIT30    = 1 << 30         // Large value for bit manipulation
	NIL          = -1               // Nil value indicator
	// Constants for graph algorithms
	WHITE = 0 // Unvisited node
	GRAY  = 1 // Visited node
	BLACK = 2 // Fully processed node
)

// Initialization function to set up input and output
func init() {
	// Set up the input reading function to read words
	ReadString = newReadString(os.Stdin, bufio.ScanWords)
	// Initialize buffered output
	stdout = bufio.NewWriter(os.Stdout)
}

// Global variables for the number of nodes and edges
var (
	n, m  int       // n: number of nodes, m: modulus
	edges [][]int   // edges: adjacency list for the graph
)

func main() {
	// Read the number of nodes and edges
	n, m = ReadInt2()
	// Read edges and build the adjacency list
	for i := 0; i < n-1; i++ {
		x, y := ReadInt2() // Read each edge
		x--                // Convert to zero-based index
		y--

		e := []int{x, y} // Create edge
		edges = append(edges, e) // Append edge to the list
	}

	// Define operations for the re-rooting solver
	f := func(x, y T) T { return T(int(x) * int(y) % m) } // Multiplication operation
	g := func(v T, p int) T { return v + 1 }               // Increment operation

	// Create a new re-rooting solver instance
	s := NewReRootingSolver(n, edges, 1, f, g)
	// Query results for each node and print them
	for i := 0; i < n; i++ {
		fmt.Println(s.Query(i) - 1) // Output the result for each node
	}
}

// Type definition for generic operations
type T int

// Structure for the re-rooting solver
type ReRootingSolver struct {
	NodeCount         int   // Number of nodes
	Adjacents         [][]int // Adjacency list
	IndexForAdjacents [][]int // Index mapping for adjacency
	Res               []T    // Result array
	DP                [][]T   // Dynamic programming table

	Identity    T                    // Identity element for operations
	Operate     func(l, r T) T      // Operation function
	OperateNode func(v T, p int) T  // Node operation function
}

// Constructor for ReRootingSolver
func NewReRootingSolver(
	nodeCount int, edges [][]int, identity T, operate func(l, r T) T, operateNode func(v T, p int) T,
) *ReRootingSolver {
	s := new(ReRootingSolver)

	// Initialize the solver with parameters
	s.NodeCount = nodeCount
	s.Identity = identity
	s.Operate = operate
	s.OperateNode = operateNode

	// Initialize adjacency lists
	s.Adjacents = make([][]int, nodeCount)
	s.IndexForAdjacents = make([][]int, nodeCount)
	for _, e := range edges {
		// Build adjacency list and index mapping
		s.IndexForAdjacents[e[0]] = append(s.IndexForAdjacents[e[0]], len(s.Adjacents[e[1]]))
		s.IndexForAdjacents[e[1]] = append(s.IndexForAdjacents[e[1]], len(s.Adjacents[e[0]]))
		s.Adjacents[e[0]] = append(s.Adjacents[e[0]], e[1])
		s.Adjacents[e[1]] = append(s.Adjacents[e[1]], e[0])
	}

	// Initialize DP and result arrays
	s.DP = make([][]T, len(s.Adjacents))
	s.Res = make([]T, len(s.Adjacents))

	for i := 0; i < len(s.Adjacents); i++ {
		s.DP[i] = make([]T, len(s.Adjacents[i])) // Allocate DP table
	}

	// Initialize the solver if there are more than one node
	if s.NodeCount > 1 {
		s.Initialize()
	} else {
		// Base case for a single node
		s.Res[0] = s.OperateNode(s.Identity, 0)
	}

	return s
}

// Query function to get the result for a specific node
func (s *ReRootingSolver) Query(node int) T {
	return s.Res[node] // Return the result for the queried node
}

// Initialize the re-rooting solver
func (s *ReRootingSolver) Initialize() {
	parents, order := make([]int, s.NodeCount), make([]int, s.NodeCount)

	// Depth-first search to establish parent-child relationships and order of nodes
	index := 0
	stack := []int{}
	stack = append(stack, 0) // Start from the root node
	parents[0] = -1          // Root has no parent
	for len(stack) > 0 {
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		order[index] = node // Record the order of nodes
		index++
		for i := 0; i < len(s.Adjacents[node]); i++ {
			adjacent := s.Adjacents[node][i]
			if adjacent == parents[node] {
				continue // Skip the parent node
			}
			stack = append(stack, adjacent) // Add child to the stack
			parents[adjacent] = node        // Set parent
		}
	}

	// Process nodes from leaves to root
	for i := len(order) - 1; i >= 1; i-- {
		node := order[i]
		parent := parents[node]

		accum := s.Identity // Initialize accumulator
		parentIndex := -1
		for j := 0; j < len(s.Adjacents[node]); j++ {
			if s.Adjacents[node][j] == parent {
				parentIndex = j // Find index of parent
				continue
			}
			accum = s.Operate(accum, s.DP[node][j]) // Accumulate results from children
		}
		s.DP[parent][s.IndexForAdjacents[node][parentIndex]] = s.OperateNode(accum, node) // Update DP for parent
	}

	// Process nodes from root to leaves
	for i := 0; i < len(order); i++ {
		node := order[i]
		accum := s.Identity // Initialize accumulator
		accumsFromTail := make([]T, len(s.Adjacents[node]))
		accumsFromTail[len(accumsFromTail)-1] = s.Identity // Initialize tail accumulator
		for j := len(accumsFromTail) - 1; j >= 1; j-- {
			accumsFromTail[j-1] = s.Operate(s.DP[node][j], accumsFromTail[j]) // Accumulate results from tail
		}
		for j := 0; j < len(accumsFromTail); j++ {
			// Update DP for adjacent nodes
			s.DP[s.Adjacents[node][j]][s.IndexForAdjacents[node][j]] = s.OperateNode(s.Operate(accum, accumsFromTail[j]), node)
			accum = s.Operate(accum, s.DP[node][j]) // Update accumulator
		}
		s.Res[node] = s.OperateNode(accum, node) // Store result for the node
	}
}

/*******************************************************************/

/*********** I/O ***********/

// Global variables for input reading functions
var (
	ReadString func() string // Function to read a string
	stdout     *bufio.Writer // Buffered output writer
)

// Function to create a new input reading function
func newReadString(ior io.Reader, sf bufio.SplitFunc) func() string {
	r := bufio.NewScanner(ior)
	r.Buffer(make([]byte, 1024), int(1e+9)) // Set buffer size for large inputs
	r.Split(sf)

	return func() string {
		if !r.Scan() {
			panic("Scan failed") // Panic if scanning fails
		}
		return r.Text() // Return scanned text
	}
}

// ReadInt returns an integer.
func ReadInt() int {
	return int(readInt64()) // Convert int64 to int
}

// ReadInt2 returns two integers.
func ReadInt2() (int, int) {
	return int(readInt64()), int(readInt64()) // Read two integers
}

// ReadInt3 returns three integers.
func ReadInt3() (int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64()) // Read three integers
}

// ReadInt4 returns four integers.
func ReadInt4() (int, int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64()), int(readInt64()) // Read four integers
}

// ReadInt64 returns an int64.
func ReadInt64() int64 {
	return readInt64() // Read int64 value
}

// ReadInt64_2 returns two int64 values.
func ReadInt64_2() (int64, int64) {
	return readInt64(), readInt64() // Read two int64 values
}

// ReadInt64_3 returns three int64 values.
func ReadInt64_3() (int64, int64, int64) {
	return readInt64(), readInt64(), readInt64() // Read three int64 values
}

// ReadInt64_4 returns four int64 values.
func ReadInt64_4() (int64, int64, int64, int64) {
	return readInt64(), readInt64(), readInt64(), readInt64() // Read four int64 values
}

// Helper function to read an int64 from input
func readInt64() int64 {
	i, err := strconv.ParseInt(ReadString(), 0, 64) // Parse input string to int64
	if err != nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i // Return parsed int64
}

// ReadIntSlice returns a slice of integers of size n.
func ReadIntSlice(n int) []int {
	b := make([]int, n) // Create a slice of size n
	for i := 0; i < n; i++ {
		b[i] = ReadInt() // Fill the slice with integers
	}
	return b // Return the slice
}

// ReadInt64Slice returns a slice of int64 of size n.
func ReadInt64Slice(n int) []int64 {
	b := make([]int64, n) // Create a slice of size n
	for i := 0; i < n; i++ {
		b[i] = ReadInt64() // Fill the slice with int64 values
	}
	return b // Return the slice
}

// ReadFloat64 returns a float64.
func ReadFloat64() float64 {
	return float64(readFloat64()) // Convert read value to float64
}

// Helper function to read a float64 from input
func readFloat64() float64 {
	f, err := strconv.ParseFloat(ReadString(), 64) // Parse input string to float64
	if err != nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return f // Return parsed float64
}

// ReadFloat64Slice returns a slice of float64 of size n.
func ReadFloat64Slice(n int) []float64 {
	b := make([]float64, n) // Create a slice of size n
	for i := 0; i < n; i++ {
		b[i] = ReadFloat64() // Fill the slice with float64 values
	}
	return b // Return the slice
}

// ReadRuneSlice returns a slice of runes.
func ReadRuneSlice() []rune {
	return []rune(ReadString()) // Convert input string to rune slice
}

/*********** Debugging ***********/

// ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding.
// For debugging use.
func ZeroPaddingRuneSlice(n, digitsNum int) []rune {
	sn := fmt.Sprintf("%b", n) // Convert integer to binary string

	residualLength := digitsNum - len(sn) // Calculate padding length
	if residualLength <= 0 {
		return []rune(sn) // Return binary string if no padding needed
	}

	// Create zero padding
	zeros := make([]rune, residualLength)
	for i := 0; i < len(zeros); i++ {
		zeros[i] = '0' // Fill with zeros
	}

	res := []rune{}
	res = append(res, zeros...) // Append zeros
	res = append(res, []rune(sn)...) // Append binary string

	return res // Return padded binary string
}

// Strtoi is a wrapper of strconv.Atoi().
// If strconv.Atoi() returns an error, Strtoi calls panic.
func Strtoi(s string) int {
	if i, err := strconv.Atoi(s); err != nil {
		panic(errors.New("[argument error]: Strtoi only accepts integer string")) // Panic on error
	} else {
		return i // Return parsed integer
	}
}

// PrintIntsLine returns integers string delimited by a space.
func PrintIntsLine(A ...int) string {
	res := []rune{}

	for i := 0; i < len(A); i++ {
		str := strconv.Itoa(A[i]) // Convert integer to string
		res = append(res, []rune(str)...)

		if i != len(A)-1 {
			res = append(res, ' ') // Add space delimiter
		}
	}

	return string(res) // Return the concatenated string
}

// PrintInts64Line returns integers string delimited by a space.
func PrintInts64Line(A ...int64) string {
	res := []rune{}

	for i := 0; i < len(A); i++ {
		str := strconv.FormatInt(A[i], 10) // Convert int64 to string
		res = append(res, []rune(str)...)

		if i != len(A)-1 {
			res = append(res, ' ') // Add space delimiter
		}
	}

	return string(res) // Return the concatenated string
}

// PrintfDebug is wrapper of fmt.Fprintf(os.Stderr, format, a...)
func PrintfDebug(format string, a ...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...) // Print debug information to stderr
}

// PrintfBufStdout is function for output strings to buffered os.Stdout.
// You may have to call stdout.Flush() finally.
func PrintfBufStdout(format string, a ...interface{}) {
	fmt.Fprintf(stdout, format, a...) // Print formatted output to buffered stdout
}
