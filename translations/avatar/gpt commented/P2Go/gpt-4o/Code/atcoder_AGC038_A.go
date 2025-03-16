package main

import (
	"fmt"
	"os"
)

func solve(H int, W int, A int, B int) {
	// Initialize a 2D slice (matrix) with dimensions H x W filled with "0"
	answer := make([][]string, H)
	for i := range answer {
		answer[i] = make([]string, W)
		for j := range answer[i] {
			answer[i][j] = "0"
		}
	}

	// Fill the matrix based on the conditions involving A and B
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			// If we are in the first B rows
			if i < B {
				// If we are in the first A columns
				if j < A {
					answer[i][j] = "0" // Set to "0"
				} else {
					answer[i][j] = "1" // Set to "1" for columns >= A
				}
			} else {
				// If we are in rows >= B
				if j < A {
					answer[i][j] = "1" // Set to "1" for columns < A
				} else {
					answer[i][j] = "0" // Set to "0" for columns >= A
				}
			}
		}
	}

	// Print the resulting matrix row by row
	for i := 0; i < H; i++ {
		fmt.Println(join(answer[i]))
	}
}

func join(arr []string) string {
	result := ""
	for _, s := range arr {
		result += s
	}
	return result
}

func main() {
	var H, W, A, B int

	// Read input values for H, W, A, and B
	_, err := fmt.Scan(&H, &W, &A, &B)
	if err != nil {
		fmt.Fprintln(os.Stderr, "Error reading input:", err)
		return
	}

	// Call the solve function with the input parameters
	solve(H, W, A, B)
}

// <END-OF-CODE>
