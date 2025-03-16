package main

import (
	"fmt"
	"strings"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w) // Read height and width from standard input
	s := "snuke"      // Initialize the pattern string

	for i := 0; i < h; i++ { // Iterate through each row of the grid
		for j := 0; j < w; j++ { // Iterate through each column of the grid
			var t string
			fmt.Scan(&t) // Read a string from standard input
			if strings.Compare(s, t) == 0 { // Check if current string matches the pattern 'snuke'
				c := 'A' + rune(j) // Calculate the column index 'j' of the matching character
				fmt.Printf("%c%d\n", c, i+1) // Print the character and its row number to standard output
				return // Exit the program if a match is found
			}
		}
	}

	// Return 0 if no match is found (implicit in Go)
}

// <END-OF-CODE>
