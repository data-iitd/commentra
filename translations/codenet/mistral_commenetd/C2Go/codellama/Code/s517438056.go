
package main

import (
	"fmt"
	"math"
	"os"
)

func main() {
	// Read the number of rows and columns from the user
	fmt.Print("Enter the number of rows and columns: ")
	var N, D int
	_, err := fmt.Scan(&N, &D)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	// Allocate memory for the 2D matrix
	matrix := make([][]int, N)
	for i := 0; i < N; i++ {
		matrix[i] = make([]int, D)
	}

	// Read the elements of the matrix from the user
	fmt.Println("Enter the elements of the matrix:")
	for i := 0; i < N; i++ {
		fmt.Printf("Row %d: ", i+1)
		for j := 0; j < D; j++ {
			_, err := fmt.Scan(&matrix[i][j])
			if err != nil {
				fmt.Println(err)
				os.Exit(1)
			}
		}
	}

	// Calculate the number of identical rows
	k := 0
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			m := 0 // Initialize the variable m to 0
			for n := 0; n < D; n++ {
				// Calculate the difference between the corresponding elements of two rows and square it
				m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n])
			}
			// Calculate the square root of the sum of squared differences
			l := math.Sqrt(float64(m))
			// If the square root is an integer, increment the counter k
			if math.Ceil(l) == math.Floor(l) {
				k++
			}
		}
	}

	// Print the result
	fmt.Println(k)
}

