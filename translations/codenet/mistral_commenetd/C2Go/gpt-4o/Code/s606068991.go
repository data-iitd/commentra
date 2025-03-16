package main

import (
	"fmt"
)

// Function to print the first n-1 elements of an array
func white(n int, A []int) {
	// Loop to print the first n-1 elements of the array
	for i := 0; i < n-1; i++ {
		fmt.Printf("%d ", A[i])
	}
	// Print the last element of the array
	fmt.Println(A[n-1])
}

// Function to implement insertion sort algorithm
func insertionsort(n int, A []int) {
	// Loop to sort the array using insertion sort algorithm
	for i := 0; i < n; i++ {
		// Inner loop to find the position of the current element in sorted array
		for j := 0; j < i; j++ {
			// Swap if current element is smaller than the previous one
			if A[i] < A[j] {
				// Swap the elements
				A[i], A[j] = A[j], A[i]
			}
		}
		// Call the white function to print the sorted array after each iteration
		white(n, A)
	}
}

// Main function to take input and call the insertion sort function
func main() {
	var n int
	var A [100]int
	// Take the size of the array as input
	fmt.Scan(&n)
	// Take the elements of the array as input
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	// Call the insertion sort function to sort the array
	insertionsort(n, A[:n])
}

// <END-OF-CODE>
