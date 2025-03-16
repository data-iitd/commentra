package main

import (
	"fmt"
)

func main() {
	// Create an instance of Main and invoke the run method
	run()
}

func run() {
	// Initialize a Scanner to read input from the console
	var N, M int
	fmt.Scan(&N, &M)

	// Create a slice to store bitwise representations for each element
	a := make([]int, N)

	// Read M groups of integers and update the bitwise representation
	for i := 0; i < M; i++ {
		var k int
		fmt.Scan(&k) // Read the number of integers in the current group
		for j := 0; j < k; j++ {
			var s int
			fmt.Scan(&s) // Read the integer
			s--          // Convert to zero-based index
			// Update the bitwise representation for the element
			a[s] |= (1 << i)
		}
	}

	// Read M integers to create a bitmask p
	var p int
	for i := 0; i < M; i++ {
		var x int
		fmt.Scan(&x) // Read the integer
		p |= (x << i) // Update the bitmask p
	}

	// Initialize a counter for valid combinations
	ans := 0

	// Iterate through all possible subsets of N elements
	for s := 0; s < (1 << N); s++ {
		t := 0 // Initialize a temporary variable to store the XOR result
		for i := 0; i < N; i++ {
			// Check if the i-th element is included in the subset
			if (s>>i)&1 == 1 {
				// XOR the current element's bitwise representation
				t ^= a[i]
			}
		}
		// Check if the XOR result matches the bitmask p
		if p == t {
			ans++ // Increment the count of valid combinations
		}
	}

	// Output the total count of valid combinations
	fmt.Println(ans)
}

// <END-OF-CODE>
