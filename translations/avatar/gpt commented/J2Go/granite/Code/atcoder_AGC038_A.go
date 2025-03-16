
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object for input and a BufferedWriter for output
	sc := bufio.NewScanner(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)

	// Read the dimensions of the grid and the parameters A and B
	var H, W, A, B int
	fmt.Fscanf(sc, "%d %d %d %d\n", &H, &W, &A, &B)

	// Check if the grid can accommodate the required number of 0s and 1s
	if W < 2*A || H < 2*B {
		fmt.Fprintln(bw, -1) // Print -1 if the grid is too small
		bw.Flush()
		return // Exit the program
	}

	// Generate the grid based on the parameters A and B
	for i := 0; i < H; i++ { // Iterate over each row
		for j := 0; j < W; j++ { // Iterate over each column
			// Determine whether to write '0' or '1' based on the current position
			if (i < B && j < A) || (i >= B && j >= A) {
				fmt.Fprint(bw, "0") // Write '0' for specified conditions
			} else {
				fmt.Fprint(bw, "1") // Write '1' otherwise
			}
		}
		fmt.Fprintln(bw) // Move to the next line after finishing a row
	}

	// Flush the BufferedWriter to ensure all data is written out
	bw.Flush()
}

