package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n int
	var m uint64

	// Initialize variables
	fmt.Scan(&n)
	// Assign the value of n to m for later use
	m = uint64(n)
	// Decrement n by 1
	n--

	// Loop through n-1 times to calculate the factorial
	for ; n > 1; n-- {
		// Multiply m with current value of n
		m *= uint64(n)
	}

	// Print the result
	fmt.Println(m)
}

