package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a scanner object for input and a buffered writer for output
	sc := bufio.NewScanner(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)

	// Read the dimensions of the grid and the parameters A and B
	var H, W, A, B int
	fmt.Scan(&H, &W, &A, &B)

	// Check if the grid can accommodate the required number of 0s and 1s
	if W < 2*A || H < 2*B {
		fmt.Println(-1)
		return
	}

	// Generate the grid based on the parameters A and B
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			// Determine whether to write '0' or '1' based on the current position
			if (i < B && j < A) || (i >= B && j >= A) {
				bw.WriteString("0")
			} else {
				bw.WriteString("1")
			}
		}
		bw.WriteString("\n")
	}

	// Flush the buffered writer to ensure all data is written out
	bw.Flush()
}

