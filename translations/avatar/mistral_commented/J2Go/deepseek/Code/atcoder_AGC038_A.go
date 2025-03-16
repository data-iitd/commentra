package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	var H, W, A, B int

	// Read input values for H, W, A, and B
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &H)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &W)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &A)
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &B)

	// Check if the grid dimensions meet the conditions
	if W < 2*A || H < 2*B {
		fmt.Println(-1) // Print -1 if the conditions are not met
		return
	}

	// Write the grid to the output
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			// Write '0' if the current cell is outside the given rectangular region, otherwise write '1'
			if (i < B && j < A) || (i >= B && j >= A) {
				writer.WriteString("0")
			} else {
				writer.WriteString("1")
			}
		}
		writer.WriteString("\n") // Move to the next line after writing a row
	}

	// Flush the buffer to write the output to the console
	writer.Flush()
}

