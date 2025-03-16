// Package main is the entry point of the program
package main

import (
	// bufio package is used for reading from I/O buffers
	"bufio"
	// fmt package is used for printing output
	"fmt"
	// os package is used for opening the standard input and output streams
	"os"
	// sort package is used for sorting arrays
	"sort"
	// strconv package is used for converting strings to integers
	"strconv"
)

// Function out is used for printing output to the console
func out(x ...interface{}) {
	fmt.Println(x...)
}

// Variable sc is used for reading input from the standard input stream
var sc = bufio.NewScanner(os.Stdin)

// Function getInt is used for reading an integer value from the standard input
func getInt() int {
	sc.Scan()
	// Convert the scanned text to an integer value
	i, e := strconv.Atoi(sc.Text())
	// If an error occurs during the conversion, panic with the error
	if e != nil {
		panic(e)
	}
	// Return the integer value
	return i
}

// Function getString is used for reading a string value from the standard input
func getString() string {
	sc.Scan()
	// Return the scanned text as a string value
	return sc.Text()
}

// Function max returns the maximum value between two integers
func max(a, b int) int {
	// If the first integer is greater than the second integer, return the first integer
	if a > b {
		return a
	}
	// Otherwise, return the second integer
	return b
}

// Function min returns the minimum value between two integers
func min(a, b int) int {
	// If the first integer is less than the second integer, return the first integer
	if a < b {
		return a
	}
	// Otherwise, return the second integer
	return b
}

// Function asub returns the absolute difference between two integers
func asub(a, b int) int {
	// If the first integer is greater than the second integer, return the difference
	if a > b {
		return a - b
	}
	// Otherwise, return the negative difference
	return b - a
}

// Function abs returns the absolute value of an integer
func abs(a int) int {
	// If the integer is greater than or equal to zero, return the integer itself
	if a >= 0 {
		return a
	}
	// Otherwise, return the negative of the integer
	return -a
}

// Function lowerBound returns the index of the first element in the slice that is greater than or equal to the given value
func lowerBound(a []int, x int) int {
	// Use the sort.Search function to find the index
	idx := sort.Search(len(a), func(i int) bool {
		// Return true if the element at the index is greater than or equal to the given value
		return a[i] >= x
	})
	// Return the index
	return idx
}

// Function upperBound returns the index of the first element in the slice that is greater than the given value
func upperBound(a []int, x int) int {
	// Use the sort.Search function to find the index
	idx := sort.Search(len(a), func(i int) bool {
		// Return true if the element at the index is greater than the given value
		return a[i] > x
	})
	// Return the index
	return idx
}

// Type shop represents a data structure for storing two integers
type shop struct {
	a, b int
}

// Type Datas is a slice of shop data structures
type Datas []shop

// Function Len returns the length of the Datas slice
func (p Datas) Len() int {
	return len(p)
}

// Function Swap swaps the positions of two elements in the Datas slice
func (p Datas) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

// Function Less compares two shop data structures and returns true if the first one should come before the second one in a sorted slice
func (p Datas) Less(i, j int) bool {
	// Compare the 'a' fields of the two shop structures
	return p[i].a < p[j].a
}

// Main function is the entry point of the program
func main() {
	// Initialize the scanner for reading input from the standard input
	sc.Split(bufio.ScanWords)

	// Read the number of shops N and the number of customers M from the standard input
	N, M := getInt(), getInt()
	// Initialize a slice of shop data structures named s with a length of N
	s := make(Datas, N)
	// For each shop in the slice
	for i := 0; i < N; i++ {
		// Read the capacity 'a' and demand 'b' of the shop from the standard input
		a, b := getInt(), getInt()
		// Create a new shop data structure with the read values and assign it to the i-th position in the slice
		s[i] = shop{a, b}
	}
	// Sort the slice in ascending order based on the 'a' field of each shop
	sort.Sort(s)

	// Initialize a variable named total to store the total capacity used by the shops
	total := 0
	// For each shop in the sorted slice
	for _, e := range s {
		// Calculate the minimum capacity that can be served by the shop without exceeding the maximum demand
		n := min(e.b, M)
		// Add the capacity of the shop multiplied by the number of customers it can serve to the total capacity
		total += n * e.a
		// Decrease the maximum demand by the number of customers served by the shop
		M -= n
		// If the maximum demand becomes zero, break the loop
		if M == 0 {
			break
		}
	}
	// Print the total capacity used by the shops
	out(total)
}

