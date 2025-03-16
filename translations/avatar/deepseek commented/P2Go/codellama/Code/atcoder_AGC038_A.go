
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(H int, W int, A int, B int) {
	// Initialize the answer matrix with "0"
	answer := make([][]string, H)
	for i := range answer {
		answer[i] = make([]string, W)
		for j := range answer[i] {
			answer[i][j] = "0"
		}
	}

	// Fill the matrix based on the given conditions
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			if i < B { // Check if the row index is less than B
				if j < A { // Check if the column index is less than A
					answer[i][j] = "0" // Assign "0" if both conditions are met
				} else {
					answer[i][j] = "1" // Assign "1" otherwise
				}
			} else { // If the row index is not less than B
				if j < A {
					answer[i][j] = "1" // Assign "1" if the column index is less than A
				} else {
					answer[i][j] = "0" // Assign "0" otherwise
				}
			}
		}
	}

	// Print each row of the matrix as a string
	for i := 0; i < H; i++ {
		fmt.Println(strings.Join(answer[i], ""))
	}
}

func main() {
	tokens := make([]string, 0)
	for _, line := range os.Args[1:] {
		tokens = append(tokens, strings.Split(line, " ")...)
	}

	H, _ := strconv.Atoi(tokens[0]) // Read the height
	W, _ := strconv.Atoi(tokens[1]) // Read the width
	A, _ := strconv.Atoi(tokens[2]) // Read the number of columns to be filled with "0"
	B, _ := strconv.Atoi(tokens[3]) // Read the number of rows to be filled with "0"

	solve(H, W, A, B) // Call the solve function with the read values
}

// 