
package main

import "fmt"

func main() {
	// Declare variables
	var m, n int
	var i, j int
	var A [100][100]int
	var B [100]int
	var S [100]int

	// Read the dimensions of the matrices from user
	fmt.Scanf("%d %d", &m, &n)
	// Comments for the for loop: Read the elements of matrix A row-wise
	for i = 0; i < m; i++ {
		for j = 0; j < n-1; j++ {
			fmt.Scanf("%d ", &A[i][j])
		}
		// Read the last element of the row
		fmt.Scanf("%d\n", &A[i][n-1])
	}
	// Comments for the for loop: Read the elements of vector B
	for i = 0; i < n; i++ {
		fmt.Scanf("%d\n", &B[i])
	}
	// Comments for the for loop: Perform element-wise multiplication of matrices A and B, and store the result in vector S
	for i = 0; i < m; i++ {
		for j = 0; j < n; j++ {
			S[i] += A[i][j] * B[j]
		}
	}
	// Comments for the for loop: Print the elements of vector S
	for i = 0; i < m; i++ {
		fmt.Printf("%d\n", S[i])
	}

	// The program ends with a return statement with value 0
	return
}

