package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(H int, W int, A int, B int) {
	// Initialize a 2D slice named 'answer' of size H x W with all elements set to the string "0".
	answer := make([][]string, H)
	for i := 0; i < H; i++ {
		answer[i] = make([]string, W)
		for j := 0; j < W; j++ {
			answer[i][j] = "0"
		}
	}

	// Iterate through each row 'i' in the range of H.
	for i := 0; i < H; i++ {
		// Iterate through each column 'j' in the range of W.
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

	// Iterate through each row 'i' in the range of H and print its elements joined by an empty string.
	for i := 0; i < H; i++ {
		fmt.Println(answer[i])
	}
}

func main() {
	// Create a new scanner to read input from standard input.
	scanner := bufio.NewScanner(os.Stdin)

	// Read the input tokens and assign them to the variables H, W, A, and B.
	scanner.Scan()
	H, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	W, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	A, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	B, _ := strconv.Atoi(scanner.Text())

	// Call the 'solve' function with the given input.
	solve(H, W, A, B)
}

