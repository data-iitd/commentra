package main

import (
	"fmt"
)

// Function to print the array elements
func white(n int, A []int) {
	// Loop through the array elements except the last one
	for i := 0; i < n-1; i++ {
		fmt.Printf("%d ", A[i]) // Print each element followed by a space
	}
	fmt.Printf("%d\n", A[n-1]) // Print the last element followed by a newline
}

// Function to perform insertion sort on the array
func insertionsort(n int, A []int) {
	var a int
	// Loop through each element in the array
	for i := 0; i < n; i++ {
		// Compare the current element with the previous elements
		for j := 0; j < i; j++ {
			// If the current element is smaller, swap it with the previous element
			if A[i] < A[j] {
				a = A[i]
				A[i] = A[j]
				A[j] = a // Swap the elements
			}
		}
		// Print the current state of the array after each insertion
		white(n, A)
	}
}

func main() {
	var i, n int
	var A [100]int // Declare the array

	// Read the number of elements from user input
	fmt.Scan(&n)
	// Read the elements of the array from user input
	for i = 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	// Call the insertion sort function to sort the array
	insertionsort(n, A[:])
}

