package main

import (
	"fmt"
)

func main() {
	var k int
	fmt.Scan(&k) // Read the integer k from input

	t := 0 // Initialize a variable to hold the current value of t

	// Loop through numbers from 1 to k
	for i := 1; i <= k; i++ {
		// Update t by appending a '7' at the end and taking modulo k
		t = (t % k) * 10 + 7

		// Check if the current value of t is divisible by k
		if t%k == 0 {
			fmt.Println(i) // Print the current index if divisible
			return
		}
	}
	// If no index was found, print -1
	fmt.Println(-1)
}

// <END-OF-CODE>
