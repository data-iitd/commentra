
package main

import (
	"fmt"
	"sort"
)

// Function main is the entry point of the program
func main() {
	// Initialize an integer slice named in with a length of 3
	in := make([]int, 3)

	// Use fmt.Scan to read three integers from the standard input and store them in the slice in
	fmt.Scan(&in[0], &in[1], &in[2])

	// Sort the integers in ascending order using sort.Ints function
	sort.Ints(in)

	// Multiply the last integer by 10 and add the second last and the last integer
	// Then print the result using fmt.Println
	fmt.Println(in[2] * 10 + in[1] + in[0])
}

