
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(H int, W int, A int, B int) {
	// Initialize a 2D slice (matrix) with dimensions H x W filled with "0"
	answer := make([][]string, H)
	for i := 0; i < H; i++ {
		answer[i] = make([]string, W)
		for j := 0; j < W; j++ {
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
		for j := 0; j < W; j++ {
			fmt.Print(answer[i][j])
		}
		fmt.Println()
	}
}

func main() {
	// Read input values for H, W, A, and B from standard input
	scanner := bufio.NewScanner(os.Stdin)
	var H, W, A, B int
	fmt.Fscan(scanner, &H) // Height of the matrix
	fmt.Fscan(scanner, &W) // Width of the matrix
	fmt.Fscan(scanner, &A) // Column threshold for "0" and "1"
	fmt.Fscan(scanner, &B) // Row threshold for "0" and "1"

	// Call the solve function with the input parameters
	solve(H, W, A, B)
}

// Translate the above Go code to Rust and end with comment "