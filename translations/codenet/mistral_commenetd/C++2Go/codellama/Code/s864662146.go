
package main

import (
	"fmt"
)

func main() {
	var N int // Number of elements in the array
	fmt.Scan(&N) // Read the number of elements from the standard input

	A := make([]int, N) // Declare and initialize an array of size N
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Read each element of the array from the standard input
	}

	min_element := A[0] // Initialize minimum element variable with first element
	max_element := A[0] // Initialize maximum element variable with first element

	// Find minimum and maximum elements in the array
	for i := 0; i < N; i++ {
		if A[i] < min_element { // If current element is smaller than the current minimum
			min_element = A[i] // Update minimum element
		}
		if A[i] > max_element { // If current element is larger than the current maximum
			max_element = A[i] // Update maximum element
		}
	}

	// Print the difference between maximum and minimum elements
	fmt.Println("Difference between maximum and minimum elements:", max_element-min_element)
}

