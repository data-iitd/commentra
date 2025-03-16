package main

import (
	"fmt"
)

func nextInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

func main() {
	// Read an integer `n` from the user
	n := nextInt()
	// Initialize a variable `t` to zero
	t := 0
	// Iterate through the range of integers from 0 to n-1
	for i := 0; i < n; i++ {
		// Check if the index i is odd
		if (i+1)&1 == 1 {
			// If it is odd, increment the variable t by 1
			t++
		}
	}
	// Print the result t/n as the output
	fmt.Println(float64(t) / float64(n))
}

// <END-OF-CODE>
