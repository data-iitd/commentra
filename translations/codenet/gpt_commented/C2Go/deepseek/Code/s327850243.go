package main

import (
	"fmt"
)

func main() {
	// Declare variables for the number of rows (m) and columns (n)
	var m, n int
	// Loop counters
	var i, j int
	// Declare a 2D array A for storing the matrix and a 1D array B for the vector
	var A [100][100]int
	var B [100]int
	// Declare an array S to store the results of the matrix-vector multiplication, initialized to 0
	var S [100]int

	// Read the dimensions of the matrix (m rows and n columns)
	fmt.Scan(&m, &n)

	// Input the matrix A
	for i = 0; i < m; i++ {
		// Read each row of the matrix
		for j = 0; j < n - 1; j++ {
			fmt.Scan(&A[i][j]) // Read elements of the row
		}
		// Read the last element of the row
		fmt.Scan(&A[i][n - 1])
	}

	// Input the vector B
	for i = 0; i < n; i++ {
		fmt.Scan(&B[i]) // Read each element of the vector
	}

	// Perform matrix-vector multiplication
	for i = 0; i < m; i++ {
		for j = 0; j < n; j++ {
			S[i] = S[i] + A[i][j] * B[j] // Calculate the dot product for each row
		}
	}

	// Output the result of the multiplication
	for i = 0; i < m; i++ {
		fmt.Println(S[i]) // Print each element of the result array S
	}
}

