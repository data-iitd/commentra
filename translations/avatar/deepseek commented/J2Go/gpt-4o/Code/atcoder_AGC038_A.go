package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin) // Initializing scanner to read input from the console
	writer := bufio.NewWriter(os.Stdout)   // Initializing writer to write output to the console

	var H, W, A, B int
	fmt.Scan(&H, &W, &A, &B) // Reading the height, width, and values of A and B

	// Checking if the matrix dimensions are suitable for the given values of A and B
	if W < 2*A || H < 2*B {
		fmt.Println(-1) // Printing -1 if the matrix dimensions are not suitable
		return          // Exiting the program
	}

	// Nested loops to generate the matrix
	for i := 0; i < H; i++ {
		for j := 0; j < W; j++ {
			// Assigning 0 or 1 based on the conditions specified
			if (i < B && j < A) || (i >= B && j >= A) {
				writer.WriteString("0") // Writing 0 to the buffer
			} else {
				writer.WriteString("1") // Writing 1 to the buffer
			}
		}
		writer.WriteString("\n") // Moving to the next line after each row is written
	}

	writer.Flush() // Flushing the buffer to ensure all data is written to the console
}

// <END-OF-CODE>
