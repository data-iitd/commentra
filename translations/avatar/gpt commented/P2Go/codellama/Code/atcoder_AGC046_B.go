package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read input values A, B, C, D and convert them to integers
	input := strings.Split(strings.TrimSpace(ReadLine()), " ")
	A, _ := strconv.Atoi(input[0])
	B, _ := strconv.Atoi(input[1])
	C, _ := strconv.Atoi(input[2])
	D, _ := strconv.Atoi(input[3])

	// Define a large prime number for modulo operations
	m := 998244353

	// Initialize a 2D list (matrix) d with dimensions (C+1) x (D+1) filled with zeros
	d := make([][]int, C+1)
	for i := range d {
		d[i] = make([]int, D+1)
	}

	// Set the starting point in the matrix d at position (A, B) to 1
	d[A][B] = 1

	// Iterate over the range from A to C (inclusive) for the first dimension
	for i := A; i <= C; i++ {
		// Iterate over the range from B to D (inclusive) for the second dimension
		for j := B; j <= D; j++ {
			// Update the current cell d[i][j] using the values from the previous cells
			d[i][j] += (d[i][j-1]*i + d[i-1][j]*j - d[i-1][j-1]*(i-1)*(j-1)) % m
		}
	}

	// Output the final result from the bottom-right corner of the matrix d
	fmt.Println(d[C][D])
}

// ReadLine reads a line of text from stdin and returns it with the newline character removed.
func ReadLine() string {
	var line string
	if _, err := fmt.Scan(&line); err != nil {
		panic(err)
	}
	return line
}

