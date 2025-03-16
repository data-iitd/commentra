package main

import (
	"fmt"
)

func main() {
	// Declare and initialize variables
	var N int // Declare an integer variable named N
	fmt.Scan(&N) // Read an integer value from the standard input and store it in N
	A := make([]int, N+1) // Declare an integer slice named A with a size of N+1
	B := make([]int, N) // Declare an integer slice named B with a size of N

	// Read the elements of array A from the standard input
	for i := 0; i < N+1; i++ {
		fmt.Scan(&A[i]) // Read an integer value from the standard input and store it in the ith position of array A
	}

	// Read the elements of array B from the standard input
	for i := 0; i < N; i++ {
		fmt.Scan(&B[i]) // Read an integer value from the standard input and store it in the ith position of array B
	}

	ans := int64(0) // Initialize a variable named ans to 0

	// Nested for loop to compare each pair of elements from arrays A and B
	for i := 0; i < N; i++ {
		// site i
		if A[i] >= B[i] {
			ans += int64(B[i]) // Add the smaller element to the answer
			A[i] -= B[i] // Subtract the smaller element from the corresponding element in array A
			B[i] = 0 // Set the smaller element in array B to 0
		} else {
			ans += int64(A[i]) // Add the smaller element to the answer
			B[i] -= A[i] // Subtract the smaller element from the corresponding element in array B
			A[i] = 0 // Set the smaller element in array A to 0
		}

		// site i + 1
		if A[i+1] >= B[i] {
			ans += int64(B[i]) // Add the smaller element to the answer
			A[i+1] -= B[i] // Subtract the smaller element from the corresponding element in array A
			B[i] = 0 // Set the smaller element in array B to 0
		} else {
			ans += int64(A[i+1]) // Add the smaller element to the answer
			B[i] -= A[i+1] // Subtract the smaller element from the corresponding element in array B
			A[i+1] = 0 // Set the smaller element in array A to 0
		}
	}

	// Print the final answer
	fmt.Println(ans) // Print the value of the answer variable
}
