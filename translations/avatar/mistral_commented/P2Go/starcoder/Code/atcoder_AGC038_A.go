package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the input from standard input.
	reader := bufio.NewReader(os.Stdin)
	H, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	W, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	A, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	B, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Initialize a 2D array of size H x W.
	answer := make([][]string, H)
	for i := range answer {
		answer[i] = make([]string, W)
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
		fmt.Println(strings.Join(answer[i], ""))
	}
}

// 