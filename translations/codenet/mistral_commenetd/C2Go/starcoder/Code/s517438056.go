
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Declare variables
var N, D, i, j, k = 0, 0, 0, 0, 0
var l float64
<<<<<<< HEAD
var matrix [100][100]int
=======
var matrix [][]int
>>>>>>> 98c87cb78a (data updated)

func main() {
	// Read the number of rows and columns from the user
	fmt.Print("Enter the number of rows and columns: ")
	fmt.Scanf("%d%d", &N, &D)

<<<<<<< HEAD
=======
	// Allocate memory for the 2D matrix
	matrix = make([][]int, N)
	for i = 0; i < N; i++ {
		matrix[i] = make([]int, D)
	}

>>>>>>> 98c87cb78a (data updated)
	// Read the elements of the matrix from the user
	fmt.Print("Enter the elements of the matrix:\n")
	for i = 0; i < N; i++ {
		fmt.Printf("Row %d: ", i+1)
		for j = 0; j < D; j++ {
			fmt.Scanf("%d", &matrix[i][j])
		}
	}

	// Calculate the number of identical rows
	k = 0
	for i = 0; i < N-1; i++ {
		for j = i + 1; j < N; j++ {
			m := 0
			for n := 0; n < D; n++ {
				// Calculate the difference between the corresponding elements of two rows and square it
				m += (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n])
			}
			// Calculate the square root of the sum of squared differences
			l = math.Sqrt(float64(m))
			// If the square root is an integer, increment the counter k
			if math.Ceil(l) == math.Floor(l) {
				k++
			}
		}
	}

	// Print the result
	fmt.Printf("%d\n", k)
}

