package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read height and width of the grid
	var h, w int
	fmt.Scan(&h, &w)

	// Initialize the target string
	s := "snuke"

	// Iterate through the grid to find the target string
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			// Read the current string from input
			var t string
			fmt.Scan(&t)

			// Check if the current string matches the target string
			if strings.Compare(s, t) == 0 {
				// If found, calculate the position and print it
				c := 'A' + rune(j) // Convert column index to character
				fmt.Printf("%c%d\n", c, i+1) // Output the position in the required format
				return // Exit the program after finding the target
			}
		}
	}

	// Return 0 to indicate successful execution
}
