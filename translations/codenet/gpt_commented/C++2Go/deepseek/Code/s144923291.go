package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read height and width of the grid
	var h, w int
	fmt.Scan(&h, &w)

	// Initialize a temporary character array and the target string
	var t [10]string
	s := "snuke"

	// Iterate through the grid to find the target string
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			// Read the current string from input
			fmt.Scan(&t[j])
			// Check if the current string matches the target string
			if strings.Compare(s, t[j]) == 0 {
				// If found, calculate the position and print it
				c := 'A' + j // Convert column index to character
				fmt.Printf("%c%d\n", c, i+1) // Output the position in the required format
				return // Exit the program after finding the target
			}
		}
	}
}

