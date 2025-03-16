package main

import "fmt"

func main() {
	// Read height and width of the grid
	var h, w int
	fmt.Scanf("%d %d\n", &h, &w)

	// Initialize a temporary character array and the target string
	t := make([]byte, 10)
	s := "snuke"

	// Iterate through the grid to find the target string
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			// Read the current string from input
			fmt.Scanf("%s\n", &t)
			// Check if the current string matches the target string
			if string(t) == s {
				// If found, calculate the position and print it
				c := byte('A' + j) // Convert column index to character
				fmt.Printf("%c%d\n", c, i+1) // Output the position in the required format
				return
			}
		}
	}
}

