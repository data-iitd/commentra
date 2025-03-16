package main

import (
	"fmt"
)

func main() {
	// Read input values: n (number of elements), L (left multiplier), R (right multiplier), QL (left penalty), QR (right penalty)
	var n, L, R, QL, QR int
	fmt.Scan(&n, &L, &R, &QL, &QR)

	// Read the list of weights W
	W := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&W[i])
	}

	// Initialize a slice to store cumulative sums, starting with 0 for the base case
	sumEl := make([]int, n+1)
	sumEl[0] = 0

	// Calculate cumulative sums of the weights
	for i := 1; i <= n; i++ {
		sumEl[i] = W[i-1] + sumEl[i-1]
	}

	// Calculate the initial answer based on the total weight and the right multiplier
	answer := QR*(n-1) + sumEl[n]*R

	// Iterate through each element to find the minimum energy configuration
	for i := 1; i <= n; i++ {
		// Calculate the energy for the current configuration
		energy := L*sumEl[i] + R*(sumEl[n]-sumEl[i])

		// Adjust energy based on the position of the current element relative to the midpoint
		if i > (n - i) {
			// If the current index is in the right half, apply left penalty
			energy += (i - (n - i) - 1) * QL
		} else if (n - i) > i {
			// If the current index is in the left half, apply right penalty
			energy += ((n - i) - i - 1) * QR
		}

		// Update the answer if the current energy is less than the previously recorded answer
		if energy < answer {
			answer = energy
		}
	}

	// Print the minimum energy found
	fmt.Println(answer)
}

// <END-OF-CODE>
