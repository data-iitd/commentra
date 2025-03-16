package main

import (
	"fmt"
)

func main() {
	var n, L, R, QL, QR int
	fmt.Scan(&n, &L, &R, &QL, &QR) // Reading inputs for n, L, R, QL, QR

	W := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&W[i]) // Reading the list of weights W
	}

	// Calculating the prefix sum of the weights
	sumEl := make([]int, n+1)
	for i := 1; i <= n; i++ {
		sumEl[i] = W[i-1] + sumEl[i-1]
	}

	// Initial answer calculation based on the formula
	answer := QR*(n-1) + sumEl[n]*R

	// Loop to calculate energy for each possible split point
	for i := 1; i <= n; i++ {
		energy := L*sumEl[i] + R*(sumEl[n]-sumEl[i]) // Energy calculation
		if i > (n - i) { // If the left side is heavier
			energy += (i - (n - i) - 1) * QL // Adding QL if needed
		} else if (n - i) > i { // If the right side is heavier
			energy += ((n - i) - i - 1) * QR // Adding QR if needed
		}
		if energy < answer { // Updating the answer if a new minimum energy is found
			answer = energy
		}
	}

	fmt.Println(answer) // Output the minimum energy
}

// <END-OF-CODE>
