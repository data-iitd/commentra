package main

import (
	"fmt"
	"math"
)

func main() {
	// Initialize minA to a value larger than any possible element in A
	minA := math.Pow(10, 9) + 1
	num := 0 // Counter for the number of valid pairs

	var n, t, f int // Declare variables for input size, threshold, and frequency
	fmt.Scan(&n, &t) // Read the size of the array and the threshold value
	A := make([]int, n) // Create a slice to store the elements of the array

	// Input the elements of the array A
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	// Iterate through the array to find the minimum value and count valid pairs
	for i := 0; i < n; i++ {
		// Update minA if the current element is smaller
		if minA > float64(A[i]) {
			minA = float64(A[i])
		} else {
			// Check the difference between the current element and minA
			if f == A[i]-int(minA) {
				num++ // Increment the count if the difference matches the previous one
			} else if f < A[i]-int(minA) {
				num = 1 // Reset count if a larger difference is found
				f = A[i] - int(minA) // Update the frequency to the new difference
			}
		}
	}

	// Output the total count of valid pairs
	fmt.Println(num)
}

// <END-OF-CODE>
