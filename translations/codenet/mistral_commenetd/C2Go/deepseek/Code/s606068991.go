package main

import (
	"fmt"
)

// Function to print the first n-1 elements of an array
func white(n int, A []int) {
	for i := 0; i < n-1; i++ {
		fmt.Printf("%d ", A[i])
	}
	// Print the last element of the array
	fmt.Printf("%d\n", A[n-1])
}

// Function to implement insertion sort algorithm
func insertionsort(n int, A []int) {
	var a int
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			if A[i] < A[j] {
				// Swap the elements
				a = A[i]
				A[i] = A[j]
				A[j] = a
			}
		}
		// Call the white function to print the sorted array after each iteration
		white(n, A)
	}
}

// Main function to take input and call the insertion sort function
func main() {
	var i, n int
	var A [100]int

	// Take the size of the array as input
	fmt.Scan(&n)
	// Take the elements of the array as input
	for i = 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	// Call the insertion sort function to sort the array
	insertionsort(n, A[:])
}

