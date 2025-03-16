package main

import (
	"fmt"
	"os"
)

func main() {
	var n, t int
	// Read the number of cells (n) and the target cell (t)
	fmt.Scan(&n, &t)

	// Read the list of cells that can be jumped from each cell
	s := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
	}

	// Initialize the current cell to 0
	currentCell := 0

	// Loop until the current cell exceeds the target cell
	for currentCell <= t {
		// Update the current cell by adding the value of the cell it's currently on
		currentCell += s[currentCell-1]

		// Check if the current cell is the target cell
		if currentCell == t {
			// If yes, print "YES" and exit the program
			fmt.Println("YES")
			os.Exit(0)
		}
	}

	// If the loop finishes without finding the target cell, print "NO"
	fmt.Println("NO")
}

// <END-OF-CODE>
