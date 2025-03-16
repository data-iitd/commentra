
package main

import "fmt"

// Function to print the first n-1 elements of an array
func white(n int, A []int) {
	var i int
	// Loop to print the first n-1 elements of the array
	for i = 0; i < n-1; i++ {
		fmt.Printf("%d ", A[i])
	}
	// Print the last element of the array
	fmt.Printf("%d\n", A[i])
}

// Function to implement insertion sort algorithm
func insertionsort(n int, A []int) {
	var i, j, a int
	// Loop to sort the array using insertion sort algorithm
	for i = 0; i < n; i++ {
		// Inner loop to find the position of the current element in sorted array
		for j = 0; j < i; j++ {
			// Swap if current element is smaller than the previous one
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
	var A []int
	// Take the size of the array as input
	fmt.Scanf("%d", &n)
	// Take the elements of the array as input
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &A[i])
	}
	// Call the insertion sort function to sort the array
	insertionsort(n, A)

	// Return 0 to indicate successful execution of the program
	return 0
}

