package main

import (
	"fmt"
)

func main() {
	var N int // Number of elements in the array
	fmt.Scan(&N) // Read the number of elements from the standard input

	A := make([]int, N) // Declare and initialize a slice of size N
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Read each element of the array from the standard input
	}

	minElement := A[0] // Initialize minimum element variable with first element
	maxElement := A[0] // Initialize maximum element variable with first element

	// Find minimum and maximum elements in the array
	for i := 0; i < N; i++ {
		if A[i] < minElement { // If current element is smaller than the current minimum
			minElement = A[i] // Update minimum element
		}
		if A[i] > maxElement { // If current element is larger than the current maximum
			maxElement = A[i] // Update maximum element
		}
	}

	// Print the difference between maximum and minimum elements
	fmt.Printf("Difference between maximum and minimum elements: %d\n", maxElement-minElement)

}
