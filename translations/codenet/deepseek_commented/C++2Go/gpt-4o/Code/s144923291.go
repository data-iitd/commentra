package main

import (
	"fmt"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w) // Read the dimensions of the grid
	s := "snuke"
	for i := 0; i < h; i++ { // Loop over each row
		for j := 0; j < w; j++ { // Loop over each column
			var t string
			fmt.Scan(&t) // Read a string
			if t == s { // Compare the string with the pattern
				c := 'A' + rune(j) // Calculate the column letter
				fmt.Printf("%c%d\n", c, i+1) // Output the position in the grid
				return // Terminate the program
			}
		}
	}
}

// <END-OF-CODE>
