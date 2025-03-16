package main

import (
	"fmt"
)

func main() {
	var i, j, N int
	var A [100]int
	var tmp int
	var count int

	fmt.Scan(&N) // Read the size of the array

	for i = 0; i < N; i++ {
		fmt.Scan(&A[i]) // Read the elements of the array
	}

	// Implement Bubble Sort
	for i = 0; i < N - 1; i++ {
		for j = N - 1; j > i; j-- {
			if A[j] < A[j - 1] {
				tmp = A[j] // Swap A[j] and A[j-1]
				A[j] = A[j - 1]
				A[j - 1] = tmp
				count++ // Increment the swap counter
			}
		}
	}

	for i = 0; i < N; i++ {
		fmt.Printf("%d", A[i]) // Print the sorted array elements
		if i < N - 1 {
			fmt.Print(" ") // Print a space between elements, but not after the last element
		}
	}

	fmt.Println() // Print a newline character to end the line

	fmt.Println(count) // Print the number of swaps
}

