package main

import (
	"fmt"
)

func main() {
	// Define input variables
	var n, L, R, QL, QR int
	fmt.Scan(&n, &L, &R, &QL, &QR)

	// Read input as a slice of integers
	W := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&W[i])
	}

	// Initialize slice to store sum of elements
	sumEl := make([]int, n+1)

	// Calculate sum of elements from 1 to n
	for i := 1; i <= n; i++ {
		sumEl[i] = W[i-1] + sumEl[i-1]
	}

	// Calculate initial answer
	answer := QR*(n-1) + sumEl[n]*R

	// Iterate through all elements to find minimum energy
	for i := 1; i <= n; i++ {
		// Calculate energy for current index
		energy := L*sumEl[i] + R*(sumEl[n]-sumEl[i])

		// Check if current index is greater than its mirror index
		if i > (n - i) {
			// If true, add energy of segments between current index and its mirror index
			energy += (i - (n - i) - 1) * QL
		} else if (n - i) > i {
			// If true, add energy of segments between mirror index and current index
			energy += ((n - i) - i - 1) * QR
		}

		// Update answer if current energy is less than previous answer
		if energy < answer {
			answer = energy
		}
	}

	// Print the answer
	fmt.Println(answer)
}

// <END-OF-CODE>
