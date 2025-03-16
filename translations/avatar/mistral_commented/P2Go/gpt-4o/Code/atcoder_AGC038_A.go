package main

import (
	"fmt"
	"os"
)

func solve(H, W, A, B int) {
	// Initialize a 2D slice named 'answer' of size H x W with all elements set to the string "0".
	answer := make([][]string, H)
	for i := range answer {
		answer[i] = make([]string, W)
		for j := range answer[i] {
			answer[i][j] = "0"
		}
	}

	// Iterate through each row 'i'.
	for i := 0; i < H; i++ {
		// Iterate through each column 'j'.
		for j := 0; j < W; j++ {
			// Set the value of the cell 'answer[i][j]' based on the conditions.
			if i < B {
				if j < A {
					answer[i][j] = "0"
				} else {
					answer[i][j] = "1"
				}
			} else {
				if j < A {
					answer[i][j] = "1"
				} else {
					answer[i][j] = "0"
				}
			}
		}
	}

	// Iterate through each row 'i' and print its elements joined by an empty string.
	for i := 0; i < H; i++ {
		fmt.Println(join(answer[i], ""))
	}
}

// join function to concatenate elements of a slice into a single string.
func join(arr []string, sep string) string {
	result := ""
	for i, s := range arr {
		if i > 0 {
			result += sep
		}
		result += s
	}
	return result
}

func main() {
	var H, W, A, B int

	// Read the input values for H, W, A, and B.
	_, err := fmt.Scan(&H, &W, &A, &B)
	if err != nil {
		fmt.Fprintln(os.Stderr, "Error reading input:", err)
		return
	}

	// Call the 'solve' function with the given input.
	solve(H, W, A, B)
}

// <END-OF-CODE>
