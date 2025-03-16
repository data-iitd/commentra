package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Define a large constant for infinity
	INF := int(math.Pow10(11))
	
	// Read the number of elements in the first array A and initialize it
	A := nextInt()
	// Read the number of elements in the second array B
	B := nextInt()
	// Read the number of queries Q
	Q := nextInt()

	// Initialize the first array with boundary values
	s := make([]int, A+2)
	s[0], s[A+1] = -INF, INF
	// Populate the first array with input values
	for i := 1; i <= A; i++ {
		s[i] = nextInt()
	}

	// Initialize the second array with boundary values
	t := make([]int, B+2)
	t[0], t[B+1] = -INF, INF
	// Populate the second array with input values
	for i := 1; i <= B; i++ {
		t[i] = nextInt()
	}

	// Process each query
	for i := 0; i < Q; i++ {
		// Read the query value x
		x := nextInt()
		// Find the position in the first array where x would fit
		b, d := sort.SearchInts(s, x), sort.SearchInts(t, x)
		// Initialize the result with infinity
		res := INF

		// Check the closest values in the first array
		for _, S := range []int{s[b-1], s[b]} {
			// Check the closest values in the second array
			for _, T := range []int{t[d-1], t[d]} {
				// Calculate the distances for both possible paths
				d1, d2 := abs(S-x)+abs(T-S), abs(T-x)+abs(S-T)
				// Update the result with the minimum distance found
				res = min(res, min(d1, d2))
			}
		}

		// Output the result for the current query
		fmt.Println(res)
	}
}

// Input handling. ----------

// Initialize the scanner for reading input
var sc = bufio.NewScanner(os.Stdin)

func init() {
	// Set the buffer size and split method for the scanner
	sc.Buffer([]byte{}, math.MaxInt64)
	sc.Split(bufio.ScanWords)
}

// Function to read the next integer from input
func nextInt() int {
	sc.Scan()
	i, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}
	return i
}

// Function to read the next float from input
func nextFloat() float64 {
	sc.Scan()
	f64, err := strconv.ParseFloat(sc.Text(), 64)
	if err != nil {
		panic(err)
	}
	return f64
}

// Function to read the next string from input
func nextString() string {
	sc.Scan()
	if err := sc.Err(); err != nil {
		panic(err)
	}
	return sc.Text()
}

// ---------- Input handling.

// Utility functions. ----------

// Function to calculate the absolute value
func abs(x int) int {
	return int(math.Abs(float64(x)))
}

// Function to find the minimum of two integers
func min(x, y int) int {
	return int(math.Min(float64(x), float64(y)))
}

// Function to find the maximum of two integers
func max(x, y int) int {
	return int(math.Max(float64(x), float64(y)))
}

// ---------- Utility functions.
