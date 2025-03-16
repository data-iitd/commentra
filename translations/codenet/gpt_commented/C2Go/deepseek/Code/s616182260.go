package main

import (
	"fmt"
)

func main() {
	// Declare arrays to hold input values and intermediate calculations
	var a [3]int
	var b [3]int
	var c [3][3]int

	// Read a 3x3 matrix from user input
	for i := 0; i < 3; i++ {
		fmt.Scan(&c[i][0], &c[i][1], &c[i][2])
	}

	// Initialize the first element of array 'a' to 0
	a[0] = 0

	// Copy the first row of the matrix 'c' into array 'b'
	for i := 0; i < 3; i++ {
		b[i] = c[0][i]
	}

	// Calculate the remaining elements of array 'a' based on the first column of matrix 'c'
	for i := 1; i < 3; i++ {
		a[i] = c[i][0] - b[0]
	}

	// Verify if the matrix 'c' can be represented as the sum of arrays 'a' and 'b'
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			// Check if the current element of 'c' equals the sum of corresponding elements from 'a' and 'b'
			if c[i][j] != a[i] + b[j] {
				fmt.Println("No") // Output "No" if the condition fails
				return
			}
		}
	}

	// If all checks pass, output "Yes"
	fmt.Println("Yes")
}

