package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the size of the array

	A := make([]int, N) // Declare an array of size N

	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Read the elements of the array
	}

	// Implement Bubble Sort
	count := 0 // Swap counter
	for i := 0; i < N-1; i++ {
		for j := N - 1; j > i; j-- {
			if A[j] < A[j-1] {
				// Swap A[j] and A[j-1]
				A[j], A[j-1] = A[j-1], A[j]
				count++ // Increment the swap counter
			}
		}
	}

	for i := 0; i < N; i++ {
		fmt.Print(A[i]) // Print the sorted array elements
		if i < N-1 {
			fmt.Print(" ") // Print a space between elements, but not after the last element
		}
	}

	fmt.Println() // Print a newline character to end the line
	fmt.Println(count) // Print the number of swaps
}

// <END-OF-CODE>
