
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Generator function to iterate over input tokens
	iterateTokens := func() func() string {
		tokens := strings.Split(os.Args[1], " ")
		i := 0
		return func() string {
			if i < len(tokens) {
				i++
				return tokens[i-1]
			}
			return ""
		}
	}

	// Read input values for H, W, A, and B
	tokens := iterateTokens()
	H, _ := strconv.Atoi(tokens())  // Height of the matrix
	W, _ := strconv.Atoi(tokens())  // Width of the matrix
	A, _ := strconv.Atoi(tokens())  // Column threshold for "0" and "1"
	B, _ := strconv.Atoi(tokens())  // Row threshold for "0" and "1"

	// Initialize a 2D array (matrix) with dimensions H x W filled with "0"
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
					answer[i][j] = "0"  // Set to "0"
				} else {
					answer[i][j] = "1"  // Set to "1" for columns >= A
				}
			} else {
				// If we are in rows >= B
				if j < A {
					answer[i][j] = "1"  // Set to "1" for columns < A
				} else {
					answer[i][j] = "0"  // Set to "0" for columns >= A
				}
			}
		}
	}

	// Print the resulting matrix row by row
	for i := 0; i < H; i++ {
		fmt.Println(strings.Join(answer[i], ""))
	}
}

// 