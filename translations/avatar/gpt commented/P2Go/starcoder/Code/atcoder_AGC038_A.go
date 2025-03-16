package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input
	line, err := reader.ReadString('\n')
	if err!= nil {
		panic(err)
	}

	// Split the line into tokens
	tokens := strings.Split(line, " ")

	// Convert the tokens to integers
	H, err := strconv.Atoi(tokens[0])
	if err!= nil {
		panic(err)
	}
	W, err := strconv.Atoi(tokens[1])
	if err!= nil {
		panic(err)
	}
	A, err := strconv.Atoi(tokens[2])
	if err!= nil {
		panic(err)
	}
	B, err := strconv.Atoi(tokens[3])
	if err!= nil {
		panic(err)
	}

	// Initialize a 2D list (matrix) with dimensions H x W filled with "0"
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
			} else {
				// If we are in rows >= B
				if j < A {
					answer[i][j] = "1"  // Set to "1" for columns < A
				} else {
					answer[i][j] = "0"  // Set to "0" for columns >= A
		}
	}

	// Print the resulting matrix row by row
	for i := 0; i < H; i++ {
		fmt.Println(strings.Join(answer[i], ""))
	}
}

// 