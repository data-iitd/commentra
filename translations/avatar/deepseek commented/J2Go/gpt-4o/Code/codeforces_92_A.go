package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n) // Read the number of elements in the sequence
	fmt.Scan(&k) // Read the initial value of k

	i, req := 1, 1 // Initialize i and req to 1

	// Loop continues as long as k - req is non-negative
	for k-req >= 0 {
		k -= req // Subtract req from k if k - req is non-negative
		i++      // Increment i
		if i%n != 0 {
			req = i % n // Update req to i % n if i % n is not zero
		} else {
			req = n // Update req to n if i % n is zero
		}
	}

	fmt.Println(k) // Print the final value of k
}

// <END-OF-CODE>
