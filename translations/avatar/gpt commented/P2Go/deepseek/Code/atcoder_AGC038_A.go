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
		fmt.Println(answer[i])
	}
}

func main() {
	// Create a new scanner to read input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the first line to get H
	scanner.Scan()
	H, _ := strconv.Atoi(scanner.Text())

	// Read the second line to get W
	scanner.Scan()
	W, _ := strconv.Atoi(scanner.Text())

	// Read the third line to get A
	scanner.Scan()
	A, _ := strconv.Atoi(scanner.Text())

	// Read the fourth line to get B
	scanner.Scan()
	B, _ := strconv.Atoi(scanner.Text())

	// Call the solve function with the input parameters
	solve(H, W, A, B)
}

