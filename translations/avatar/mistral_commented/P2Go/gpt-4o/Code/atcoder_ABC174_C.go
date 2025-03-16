package main

import (
	"fmt"
)

func main() {
	// Read an integer from standard input
	var k int
	fmt.Scan(&k)

	// Initialize a variable t to 0
	t := 0

	// Loop from 1 to k
	for i := 1; i <= k; i++ {
		// Calculate the value of t using the current value of i and k
		t = (t%k)*10 + 7
		t = t % k

		// Check if t is a multiple of k
		if t == 0 {
			// Print the value of i and break out of the loop
			fmt.Println(i)
			return
		}
	}

	// If the loop completes without finding a multiple of k, print -1
	fmt.Println(-1)
}

// <END-OF-CODE>
