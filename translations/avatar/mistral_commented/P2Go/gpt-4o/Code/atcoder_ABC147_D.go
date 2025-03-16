package main

import (
	"fmt"
	"math/bits"
)

func main() {
	// Read the number of elements 'N' from the user
	var N int
	fmt.Scan(&N)

	// Create a slice to store the integers
	A := make([]int64, N)

	// Read 'N' integers from the user and store them in the slice 'A'
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Initialize the result variable to zero
	result := int64(0)

	// Iterate through each bit position 'b' from 0 to 59
	for b := 0; b < 60; b++ {
		// Calculate the sum of bits in position 'b' in all numbers of 'A'
		bs := int64(0)
		for _, num := range A {
			if (num>>b)&1 == 1 {
				bs++
			}
		}

		// Calculate the contribution of this bit position 'b' to the result
		contribution := bs * (int64(N) - bs) * (1 << b)

		// Add this contribution to the result
		result = (result + contribution) % 1000000007
	}

	// Print the final result
	fmt.Println(result)
}

// <END-OF-CODE>
