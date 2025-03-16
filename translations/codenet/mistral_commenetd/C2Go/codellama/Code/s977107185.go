
package main

import "fmt"

func main() {

	var i, j, N int // Declare variables i, j, and N
	var A [100]int // Declare an array A of size 100
	var tmp int // Declare a temporary variable tmp
	var count int = 0 // Initialize counter variable count to 0

	// Read the number of elements in the array from user input
	fmt.Scan(&N)

	// Allocate memory for the array A and read its elements from user input
	for i = 0; i < N; i++ {

		fmt.Scan(&A[i]) // Read an element of the array A
	}

	// Perform bubble sort on the array A
	for i = 0; i < N-1; i++ {

		for j = N - 1; j > i; j-- { // Iterate through the array from last to first

			if A[j] < A[j-1] { // Check if the current element is smaller than the previous one

				tmp = A[j] // Swap the elements if they are in wrong order
				A[j] = A[j-1]
				A[j-1] = tmp

				count++ // Increment the counter for each swap
			}
		}
	}

	// Print the sorted array A
	for i = 0; i < N; i++ {

		fmt.Print(A[i]) // Print an element of the array A

		if i < N-1 {
			fmt.Print(" ") // Add a space between elements, except the last one
		}

	}

	fmt.Println() // Print a newline character after the sorted array

	// Print the number of swaps (count) made during sorting
	fmt.Println(count)

	// Main function ends here with a return value of 0
	return
}

