package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// mainFn contains the core logic of the program
func mainFn() {
	// Read the number of elements
	n := getInt()
	// Read the integer slice from input
	ls := getIntSlice(n)
	// Create a reversed copy of the original slice
	lsRev := make([]int, n)
	copy(lsRev, ls)
	// Sort the original slice in ascending order
	sort.Ints(ls)
	// Sort the reversed slice in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(lsRev)))

	// Initialize the answer variable
	ans := 0
	// Iterate through all pairs of elements in the sorted slice
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			// Determine the minimum and maximum of the two selected elements
			p, q := min(ls[i], ls[j]), max(ls[i], ls[j])
			// Calculate the differences and sums needed for searching
			x, y := q-p, q+p

			// Find the left boundary for elements greater than x
			l := sort.Search(len(ls), func(i int) bool { return ls[i] > x })
			// Find the right boundary for elements less than y
			r := n - sort.Search(len(lsRev), func(i int) bool { return lsRev[i] < y })

			// Calculate the number of valid elements in the range
			sum := r - l
			// Adjust the count if the current indices are within the range
			if (i >= l) && (i <= r) {
				sum--
			}
			if (j >= l) && (j <= r) {
				sum--
			}
			// Ensure the sum is non-negative
			sum = max(0, sum)
			// Accumulate the result
			ans += sum
		}
	}

	// Divide the final answer by 3 as per the problem requirements
	ans /= 3
	// Output the result
	puts(ans)
}

// min returns the smaller of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// max returns the larger of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// -----------------------------------------

// Global variables for input and output handling
var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

// main is the entry point of the program
func main() {
	// Set the scanner to split input into words
	scanner.Split(bufio.ScanWords)
	// Call the main function to execute the logic
	mainFn()
	// Flush the buffered output
	writer.Flush()
}

// getInt reads an integer from input
func getInt() int {
	scanner.Scan()
	i, err := strconv.Atoi(scanner.Text())
	if err != nil {
		panic(err)
	}
	return i
}

// getIntSlice reads a slice of integers from input
func getIntSlice(n int) []int {
	is := make([]int, n)
	for i := range is {
		is[i] = getInt()
	}
	return is
}

// getString reads a string from input
func getString() string {
	scanner.Scan()
	s := scanner.Text()
	return s
}

// puts writes the given arguments to the output
func puts(a ...interface{}) {
	if _, err := fmt.Fprintln(writer, a...); err != nil {
		panic(err)
	}
}
