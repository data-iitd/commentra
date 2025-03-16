// Package main is the entry point of the program
package main

import (
	// bufio package is used for reading and writing lines
	"bufio"
	// fmt package is used for formatted I/O
	"fmt"
	// os package is used for interacting with the operating system
	"os"
	// sort package is used for sorting arrays
	"sort"
	// strconv package is used for converting strings to other types
	"strconv"
)

// mainFn is the main function of the program
func mainFn() {
	// Get the number of elements in the input array
	n := getInt()
	// Get the input array
	ls := getIntSlice(n)
	// Create a reversed copy of the input array
	lsRev := make([]int, n)
	// Copy the input array to the reversed copy
	copy(lsRev, ls)
	// Sort the input array in ascending order
	sort.Ints(ls)
	// Sort the reversed copy of the array in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(lsRev)))

	// Initialize the answer variable
	ans := 0
	// Iterate through all pairs of elements in the array
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			// Find the minimum and maximum elements of the current pair
			p, q := min(ls[i], ls[j]), max(ls[i], ls[j])
			// Calculate the difference between the maximum and minimum elements
			x, y := q-p, q+p
			// Find the indices of the elements greater than x and less than y in the sorted array and reversed array respectively
			l := sort.Search(len(ls), func(i int) bool { return ls[i] > x })
			r := n - sort.Search(len(lsRev), func(i int) bool { return lsRev[i] < y })
			// Calculate the sum of the difference between the indices of the greater elements in the sorted array and reversed array
			sum := r - l
			// Check if the current pair lies within the range [l, r]
			if i >= l && i <= r {
				sum--
			}
			if j >= l && j <= r {
				sum--
			}
			// Ensure that the sum is not negative
			sum = max(0, sum)
			// Add the sum to the answer variable
			ans += sum
		}
	}
	// Divide the answer by 3 and print it
	ans /= 3
	puts(ans)
}

// min returns the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// max returns the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// -----------------------------------------

// Initialize some variables for reading and writing input/output
var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

// main is the entry point of the program
func main() {
	// Set the buffer size for reading input
	//buf := 200001
	//scanner.Buffer(make([]byte, buf), buf)
	// Set the splitting function for reading input
	scanner.Split(bufio.ScanWords)
	// Call the main function
	mainFn()
	// Flush the writer buffer
	writer.Flush()
}

// getInt reads an integer from the standard input
func getInt() int {
	scanner.Scan()
	// Convert the input string to an integer and return it
	i, err := strconv.Atoi(scanner.Text())
	if err != nil {
		panic(err)
	}
	return i
}

// getIntSlice reads an array of integers from the standard input
func getIntSlice(n int) []int {
	// Allocate memory for the array
	is := make([]int, n)
	// Read each element of the array from the standard input
	for i := range is {
		is[i] = getInt()
	}
	// Return the array
	return is
}

// getString reads a string from the standard input
func getsString() string {
	scanner.Scan()
	// Return the input string
	s := scanner.Text()
	return s
}

// puts writes the given arguments to the standard output, followed by a newline character
func puts(a ...interface{}) {
	// Write the arguments to the writer buffer
	if _, err := fmt.Fprintln(writer, a...); err != nil {
		panic(err)
	}
}
