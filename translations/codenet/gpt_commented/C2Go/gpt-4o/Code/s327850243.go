package main

import (
	"fmt"
)

func main() {
	// Declare variables for the number of rows (m) and columns (n)
	var m, n int
	// Declare a 2D slice A for storing the matrix and a 1D slice B for the vector
	A := make([][]int, 100)
	for i := range A {
		A[i] = make([]int, 100)
	}
	B := make([]int, 100)
	// Declare a slice S to store the results of the matrix-vector multiplication, initialized to 0
	S := make([]int, 100)

	// Read the dimensions of the matrix (m rows and n columns)
	fmt.Scan(&m, &n)

	// Input the matrix A
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			fmt.Scan(&A[i][j]) // Read elements of the row
		}
	}

	// Input the vector B
	for i := 0; i < n; i++ {
		fmt.Scan(&B[i]) // Read each element of the vector
	}

	// Perform matrix-vector multiplication
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			S[i] += A[i][j] * B[j] // Calculate the dot product for each row
		}
	}

	// Output the result of the multiplication
	for i := 0; i < m; i++ {
		fmt.Println(S[i]) // Print each element of the result slice S
	}
}

// <END-OF-CODE>
