package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner for input and a BufferedWriter for output
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	// Read the dimensions of the grid and the parameters A and B
	scanner.Scan()
	var H, W, A, B int
	fmt.Sscanf(scanner.Text(), "%d %d %d %d", &H, &W, &A, &B)

	// Check if the grid can accommodate the required number of 0s and 1s
	if W < 2*A || H < 2*B {
		fmt.Fprintln(writer, -1) // Print -1 if the grid is too small
		writer.Flush()            // Ensure the output is written
		return                    // Exit the program
	}

	// Generate the grid based on the parameters A and B
	for i := 0; i < H; i++ { // Iterate over each row
		for j := 0; j < W; j++ { // Iterate over each column
			// Determine whether to write '0' or '1' based on the current position
			if (i < B && j < A) || (i >= B && j >= A) {
				writer.WriteString("0") // Write '0' for specified conditions
			} else {
				writer.WriteString("1") // Write '1' otherwise
			}
		}
		writer.WriteString("\n") // Move to the next line after finishing a row
	}

	// Flush the BufferedWriter to ensure all data is written out
	writer.Flush()
}
