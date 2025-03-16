package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// solve function computes the minimum total distance to a median value
func solve() {
	// Read the number of elements
	n := getInt()
	// Read the integer slice of size n
	as := getIntSlice(n)

	// Create a new slice to store adjusted values
	xs := make([]int, n)
	for i, a := range as {
		// Adjust each element by subtracting its index and adding 1
		xs[i] = a - i + 1
	}
	// Sort the adjusted values
	sort.Ints(xs)

	// Find the median value from the sorted slice
	b := xs[n/2]
	ans := 0
	// Calculate the total distance from each element to the median
	for _, x := range xs {
		ans += abs(x - b)
	}
	// Output the result
	fmt.Fprintln(wr, ans)
}

// abs function returns the absolute value of an integer
func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

// -----------------------------------------

const (
	inf = 1 << 60 // A constant representing infinity
	// mod = 1000000007 // Uncomment if modular arithmetic is needed
)

var (
	// Scanner for reading input
	sc = bufio.NewScanner(os.Stdin)
	// Writer for output
	wr = bufio.NewWriter(os.Stdout)
)

// main function initializes input/output and calls the solve function
func main() {
	// Set a maximum buffer size for the scanner
	maxBufSize := int(1e8)
	sc.Buffer(make([]byte, 4096), maxBufSize)
	// Split input by whitespace
	sc.Split(bufio.ScanWords)
	// Call the solve function to perform the main logic
	solve()
	// Flush the output buffer
	wr.Flush()
}

// getInt reads an integer from input
func getInt() (ret int) {
	sc.Scan()
	ret, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err) // Handle conversion error
	}
	return
}

// getIntSlice reads a slice of integers from input
func getIntSlice(n int) (ret []int) {
	ret = make([]int, n)
	for i := range ret {
		ret[i] = getInt() // Read each integer
	}
	return
}

// getString reads a string from input
func getString() (ret string) {
	sc.Scan()
	ret = sc.Text() // Return the scanned string
	return
}

// getRunes converts a string to a slice of runes
func getRunes() (ret []rune) {
	ret = []rune(getString()) // Convert string to runes
	return
}
