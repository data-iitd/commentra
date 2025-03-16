package main

import (
	"fmt"
)

func main() {
	var m, n int // Declare variables to store the dimensions of matrix A and vector B
	fmt.Scan(&m, &n) // Read the dimensions of matrix A and vector B

	A := make([][]int, m) // Declare a 2D slice to store matrix A
	for i := 0; i < m; i++ {
		A[i] = make([]int, n) // Initialize each row of matrix A
		for j := 0; j < n; j++ {
			fmt.Scan(&A[i][j]) // Read the elements of matrix A
		}
	}

	B := make([]int, n) // Declare a slice to store vector B
	for i := 0; i < n; i++ {
		fmt.Scan(&B[i]) // Read the elements of vector B
	}

	S := make([]int, m) // Declare a slice to store the result of matrix multiplication

	// Perform matrix multiplication of A and B and store the result in slice S
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			S[i] += A[i][j] * B[j]
		}
	}

	// Print the elements of slice S
	for i := 0; i < m; i++ {
		fmt.Println(S[i])
	}
}

// <END-OF-CODE>
