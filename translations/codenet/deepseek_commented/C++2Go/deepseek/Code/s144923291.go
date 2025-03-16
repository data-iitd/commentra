package main

import (
	"fmt"
	"strings"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w) // Read the dimensions of the grid

	// Define the pattern to search for
	s := "snuke"

	// Read the grid
	grid := make([][]string, h)
	for i := 0; i < h; i++ {
		grid[i] = make([]string, w)
		for j := 0; j < w; j++ {
			fmt.Scan(&grid[i][j]) // Read a character array
			if grid[i][j] == s { // Compare the character array with the pattern
				// Calculate the column letter
				col := string('A' + j)
				// Output the position in the grid
				fmt.Printf("%s%d\n", col, i+1)
				return
			}
		}
	}
}

