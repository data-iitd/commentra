package main

import (
	"fmt"
	"os"
)

func main() {
	var n, t int
	// Read the number of cells (n) and the target cell (t) from input
	fmt.Scan(&n, &t)

	// Read the list of jumps for each cell
	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	// Initialize the current cell position
	currentCell := 1 // Start from cell 1 (1-indexed)

	// Loop until the current cell exceeds the target cell
	for currentCell <= t {
		// Move to the next cell based on the jump value from the current cell
		currentCell += s[currentCell-1]

		// Check if the current cell is exactly the target cell
		if currentCell == t {
			fmt.Println("YES") // Print "YES" if the target cell is reached
			os.Exit(0)         // Exit the program
		}
	}

	// If the loop ends without reaching the target cell, print "NO"
	fmt.Println("NO")
}

// <END-OF-CODE>
