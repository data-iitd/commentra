package main

import (
	"fmt"
)

// Function to print the array elements
func white(n int, A []int) {
	for i := 0; i < n-1; i++ {
		fmt.Printf("%d ", A[i]) // Print each element followed by a space
	}
	fmt.Println(A[n-1]) // Print the last element followed by a newline
}

// Function to perform insertion sort on the array
func insertionsort(n int, A []int) {
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			// If the current element is smaller, swap it with the previous element
			if A[i] < A[j] {
				A[i], A[j] = A[j], A[i] // Swap the elements
			}
		}
		// Print the current state of the array after each insertion
		white(n, A)
	}
}

func main() {
	var n int
	var A [100]int // Declare an array with a maximum size of 100

	// Read the number of elements from user input
	fmt.Scan(&n)
	// Read the elements of the array from user input
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	// Call the insertion sort function to sort the array
	insertionsort(n, A[:n]) // Pass a slice of the array to the function

	return // Return to indicate successful execution
}

// <END-OF-CODE>
