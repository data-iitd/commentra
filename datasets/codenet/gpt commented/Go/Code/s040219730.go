/*
URL:
https://atcoder.jp/contests/abc174/tasks/abc174_f
*/

package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"math"
	"os"
	"sort"
	"strconv"
)

/********** FAU standard libraries **********/

//fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

//str := ReadString()               // Read a single string
//i := ReadInt()                    // Read a single integer
//X := ReadIntSlice(n)              // Read a slice of n integers
//S := ReadRuneSlice()               // Read a slice of runes
//a := ReadFloat64()                // Read a single float64
//A := ReadFloat64Slice(n)          // Read a slice of n float64s

//str := ZeroPaddingRuneSlice(num, 32) // Zero pad a rune slice
//str := PrintIntsLine(X...)           // Print integers in a single line

/*******************************************************************/

// Constants used throughout the program
const (
	MOD          = 1000000000 + 7 // Modulus value for calculations
	ALPHABET_NUM = 26              // Number of letters in the alphabet
	INF_INT64    = math.MaxInt64   // Maximum int64 value
	INF_BIT60    = 1 << 60         // 2^60
	INF_INT32    = math.MaxInt32    // Maximum int32 value
	INF_BIT30    = 1 << 30         // 2^30
	NIL          = -1              // Represents a null value

	// Constants for graph algorithms
	WHITE = 0 // Unvisited node
	GRAY  = 1 // Visited node
	BLACK = 2 // Processed node
)

func init() {
	// Initialize the input reader and output writer
	ReadString = newReadString(os.Stdin, bufio.ScanWords) // Set up the string reader
	stdout = bufio.NewWriter(os.Stdout)                    // Set up the buffered writer for stdout
}

var (
	n, q int                // Number of elements and number of queries
	C    []int              // Slice to hold the input values
	Q    []Query            // Slice to hold the queries

	P       [500000 + 50]int // Array to track the last position of each value
	Answers [500000 + 50]int // Array to hold the answers for each query
)

// Query struct to hold the details of each query
type Query struct {
	idx, l, r int // Index, left, and right bounds of the query
}

func main() {
	// Read the number of elements and queries
	n, q = ReadInt2()
	C = ReadIntSlice(n) // Read the slice of integers

	// Initialize the position array with -1 (indicating unvisited)
	for i := 1; i <= n; i++ {
		P[i] = -1
	}

	// Read each query and store it in the Q slice
	for i := 0; i < q; i++ {
		l, r := ReadInt2() // Read the left and right bounds of the query
		query := Query{idx: i, l: l, r: r} // Create a new query
		Q = append(Q, query) // Append the query to the list
	}

	// Sort the queries based on the right bound
	sort.SliceStable(Q, func(i, j int) bool { return Q[i].r < Q[j].r })
	ft := NewFenwickTree(500000 + 50) // Initialize a Fenwick Tree for range queries

	k := 0 // Pointer to track the current position in the input array
	// Process each query
	for _, query := range Q {
		// Update the Fenwick Tree for all elements up to the right bound of the current query
		for k < query.r {
			if P[C[k]] != -1 { // If the current value has been seen before
				ft.Add(P[C[k]]+1, -1) // Remove its previous occurrence from the Fenwick Tree
			}
			P[C[k]] = k // Update the last position of the current value
			ft.Add(k+1, 1) // Add the current value to the Fenwick Tree

			k++ // Move to the next position
		}
		// Calculate the answer for the current query using the Fenwick Tree
		Answers[query.idx] = ft.Sum(query.r) - ft.Sum(query.l-1)
	}

	// Output the answers for all queries
	for i := 0; i < q; i++ {
		// fmt.Println(Answers[i]) // Print each answer
		PrintfBufStdout("%d\n", Answers[i]) // Output the answer to stdout
	}
	stdout.Flush() // Flush the buffered output
}

// Fenwick Tree structure for efficient range queries
type FenwickTree struct {
	dat     []int // Array to store the tree data
	n       int   // Number of elements
	minPow2 int   // Minimum power of 2 greater than or equal to n
}

// NewFenwickTree initializes a new Fenwick Tree
func NewFenwickTree(n int) *FenwickTree {
	ft := new(FenwickTree)

	ft.dat = make([]int, n+1) // Create the data array
	ft.n = n // Set the number of elements

	// Calculate the minimum power of 2 greater than or equal to n
	ft.minPow2 = 1
	for {
		if (ft.minPow2 << 1) > n {
			break
		}
		ft.minPow2 <<= 1
	}

	return ft // Return the initialized Fenwick Tree
}

// Sum calculates the prefix sum from 1 to i (1-based)
func (ft *FenwickTree) Sum(i int) int {
	s := 0 // Variable to hold the sum

	// Traverse the tree to calculate the sum
	for i > 0 {
		s += ft.dat[i] // Add the current index value to the sum
		i -= i & (-i) // Move to the parent index
	}

	return s // Return the calculated sum
}

// Add updates the Fenwick Tree by adding x to the index i (1-based)
func (ft *FenwickTree) Add(i, x int) {
	// Update the tree for the given index
	for i <= ft.n {
		ft.dat[i] += x // Add x to the current index
		i += i & (-i) // Move to the next index
	}
}

// LowerBound returns the minimum index such that the sum is greater than or equal to w
func (ft *FenwickTree) LowerBound(w int) int {
	if w <= 0 {
		return 0 // If w is non-positive, return 0
	}

	x := 0 // Variable to hold the index
	// Traverse the tree to find the lower bound
	for k := ft.minPow2; k > 0; k /= 2 {
		if x+k <= ft.n && ft.dat[x+k] < w {
			w -= ft.dat[x+k] // Decrease w by the current index value
			x += k // Move to the next index
		}
	}

	return x + 1 // Return the found index (1-based)
}

/*******************************************************************/

/*********** I/O ***********/

// Variables for input and output
var (
	ReadString func() string // Function to read a string
	stdout     *bufio.Writer // Buffered writer for stdout
)

// newReadString initializes a new string reader
func newReadString(ior io.Reader, sf bufio.SplitFunc) func() string {
	r := bufio.NewScanner(ior) // Create a new scanner
	r.Buffer(make([]byte, 1024), int(1e+9)) // Set buffer size for large inputs
	r.Split(sf) // Set the split function

	return func() string {
		if !r.Scan() {
			panic("Scan failed") // Panic if scanning fails
		}
		return r.Text() // Return the scanned text
	}
}

// ReadInt returns an integer.
func ReadInt() int {
	return int(readInt64()) // Read and convert to int
}

// ReadInt2 returns two integers.
func ReadInt2() (int, int) {
	return int(readInt64()), int(readInt64()) // Read and convert to two ints
}

// ReadInt3 returns three integers.
func ReadInt3() (int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64()) // Read and convert to three ints
}

// ReadInt4 returns four integers.
func ReadInt4() (int, int, int, int) {
	return int(readInt64()), int(readInt64()), int(readInt64()), int(readInt64()) // Read and convert to four ints
}

// ReadInt64 returns an int64.
func ReadInt64() int64 {
	return readInt64() // Read and return as int64
}

// ReadInt64_2 returns two int64s.
func ReadInt64_2() (int64, int64) {
	return readInt64(), readInt64() // Read and return two int64s
}

// ReadInt64_3 returns three int64s.
func ReadInt64_3() (int64, int64, int64) {
	return readInt64(), readInt64(), readInt64() // Read and return three int64s
}

// ReadInt64_4 returns four int64s.
func ReadInt64_4() (int64, int64, int64, int64) {
	return readInt64(), readInt64(), readInt64(), readInt64() // Read and return four int64s
}

// readInt64 reads an int64 from input
func readInt64() int64 {
	i, err := strconv.ParseInt(ReadString(), 0, 64) // Parse the input string to int64
	if err != nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return i // Return the parsed int64
}

// ReadIntSlice returns a slice of integers of size n.
func ReadIntSlice(n int) []int {
	b := make([]int, n) // Create a slice of size n
	for i := 0; i < n; i++ {
		b[i] = ReadInt() // Read each integer into the slice
	}
	return b // Return the slice
}

// ReadInt64Slice returns a slice of int64s of size n.
func ReadInt64Slice(n int) []int64 {
	b := make([]int64, n) // Create a slice of size n
	for i := 0; i < n; i++ {
		b[i] = ReadInt64() // Read each int64 into the slice
	}
	return b // Return the slice
}

// ReadFloat64 returns a float64.
func ReadFloat64() float64 {
	return float64(readFloat64()) // Read and convert to float64
}

// readFloat64 reads a float64 from input
func readFloat64() float64 {
	f, err := strconv.ParseFloat(ReadString(), 64) // Parse the input string to float64
	if err != nil {
		panic(err.Error()) // Panic if parsing fails
	}
	return f // Return the parsed float64
}

// ReadFloat64Slice returns a slice of float64s of size n.
func ReadFloat64Slice(n int) []float64 {
	b := make([]float64, n) // Create a slice of size n
	for i := 0; i < n; i++ {
		b[i] = ReadFloat64() // Read each float64 into the slice
	}
	return b // Return the slice
}

// ReadRuneSlice returns a slice of runes.
func ReadRuneSlice() []rune {
	return []rune(ReadString()) // Convert the input string to a rune slice
}

/*********** Debugging ***********/

// ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding.
// For debugging use.
func ZeroPaddingRuneSlice(n, digitsNum int) []rune {
	sn := fmt.Sprintf("%b", n) // Convert integer to binary string

	residualLength := digitsNum - len(sn) // Calculate the number of leading zeros needed
	if residualLength <= 0 {
		return []rune(sn) // Return the binary string if no padding is needed
	}

	zeros := make([]rune, residualLength) // Create a slice of zeros
	for i := 0; i < len(zeros); i++ {
		zeros[i] = '0' // Fill the slice with '0'
	}

	res := []rune{} // Result slice to hold the final output
	res = append(res, zeros...) // Append the zeros
	res = append(res, []rune(sn)...) // Append the binary string

	return res // Return the padded binary string
}

// Strtoi is a wrapper of strconv.Atoi().
// If strconv.Atoi() returns an error, Strtoi calls panic.
func Strtoi(s string) int {
	if i, err := strconv.Atoi(s); err != nil {
		panic(errors.New("[argument error]: Strtoi only accepts integer string")) // Panic if conversion fails
	} else {
		return i // Return the converted integer
	}
}

// PrintIntsLine returns integers string delimited by a space.
func PrintIntsLine(A ...int) string {
	res := []rune{} // Result slice to hold the output

	for i := 0; i < len(A); i++ {
		str := strconv.Itoa(A[i]) // Convert each integer to string
		res = append(res, []rune(str)...) // Append the string to the result

		if i != len(A)-1 {
			res = append(res, ' ') // Add a space between integers
		}
	}

	return string(res) // Return the final string
}

// PrintInts64Line returns integers string delimited by a space.
func PrintInts64Line(A ...int64) string {
	res := []rune{} // Result slice to hold the output

	for i := 0; i < len(A); i++ {
		str := strconv.FormatInt(A[i], 10) // Convert each int64 to string
		res = append(res, []rune(str)...) // Append the string to the result

		if i != len(A)-1 {
			res = append(res, ' ') // Add a space between integers
		}
	}

	return string(res) // Return the final string
}

// PrintfDebug is wrapper of fmt.Fprintf(os.Stderr, format, a...)
func PrintfDebug(format string, a ...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...) // Print debug information to stderr
}

// PrintfBufStdout is function for output strings to buffered os.Stdout.
// You may have to call stdout.Flush() finally.
func PrintfBufStdout(format string, a ...interface{}) {
	fmt.Fprintf(stdout, format, a...) // Print formatted output to the buffered stdout
}
