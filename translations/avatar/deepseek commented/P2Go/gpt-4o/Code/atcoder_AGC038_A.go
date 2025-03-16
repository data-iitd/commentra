package main

import (
	"fmt"
	"os"
)

func solve(H int, W int, A int, B int) {
	// Initialize the answer matrix with "0"
	answer := make([][]string, H)
	for i := range answer {
		answer[i] = make([]string, W)
		for j := range answer[i] {
			answer[i][j] = "0" // Default value
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
	_, err := fmt.Scan(&H, &W, &A, &B)
	if err != nil {
		fmt.Fprintln(os.Stderr, "Error reading input:", err)
		return
	}

	solve(H, W, A, B) // Call the solve function with the read values
}

// <END-OF-CODE>
