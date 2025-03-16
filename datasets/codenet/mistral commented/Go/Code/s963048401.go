
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Initialize a scanner for reading input from stdin
var sc = bufio.NewScanner(os.Stdin)

// Function to read a single string from stdin and return it
func Scanner() string {
	sc.Scan()
	return sc.Text()
}

// Function to read an integer from stdin and return it
func intScanner() int {
	n, _ := strconv.Atoi(Scanner())
	return n
}

// Function to read a floating point number from stdin and return it
func floatScanner() float64 {
	n, _ := strconv.ParseFloat(Scanner(), 64)
	return n
}

// Function to convert a string to an integer
func stringToInt(s string) int {
	n, _ := strconv.Atoi(s)
	return n
}

// Initialize the modulus value
var mod int = 1000000007

// Initialize a buffer to store the unique elements
var buf []int

// Function to read input and process it
func main() {
	// Initialize the scanner buffer and split function for the scanner
	sc.Buffer(buf, mod)
	sc.Split(bufio.ScanWords)

	// Read the number of elements in the array
	n := intScanner()

	// Initialize an array of size n to store the elements
	as := make([]int, n)

	// Read the elements of the array into the as slice
	for i := 0; i < n; i++ {
		as[i] = intScanner()
	}

	// Initialize an empty slice xs to store the unique elements
	xs := []int{as[0]}

	// Iterate through the array and add unique elements to the xs slice
	for j := 1; j < n; j++ {
		// Binary search to find the index where the current element should be inserted in the xs slice
		idx := sort.Search(len(xs), func(i int) bool { return xs[i] < as[j] })

		// If the current element is not already present in the xs slice, append it
		if idx == len(xs) {
			xs = append(xs, as[j])
		} else {
			// Otherwise, replace the element at the found index with the current element
			xs[idx] = as[j]
		}
	}

	// Print the length of the xs slice
	fmt.Println(len(xs))
}

