

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of rows and columns from the user
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of rows and columns: ")
	text, _ := reader.ReadString('\n')
	text = strings.TrimSpace(text)
	parts := strings.Split(text, " ")
	N, _ := strconv.Atoi(parts[0])
	D, _ := strconv.Atoi(parts[1])

	// Allocate memory for the 2D matrix
	matrix := make([][]int, N)
	for i := 0; i < N; i++ {
		matrix[i] = make([]int, D)
	}

	// Read the elements of the matrix from the user
	fmt.Print("Enter the elements of the matrix:\n")
	for i := 0; i < N; i++ {
		fmt.Printf("Row %d: ", i+1)
		text, _ := reader.ReadString('\n')
		text = strings.TrimSpace(text)
		parts = strings.Split(text, " ")
		for j := 0; j < D; j++ {
			matrix[i][j], _ = strconv.Atoi(parts[j])
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
			if math.Mod(l, 1) == 0 {
				k++
			}
		}
	}

	// Print the result
	fmt.Println(k)
}

