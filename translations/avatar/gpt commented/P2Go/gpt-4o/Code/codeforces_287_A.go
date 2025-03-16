package main

import (
	"fmt"
)

func main() {
	// Initialize an empty slice to store the input grid
	var t [4][4]rune

	// Read 4 lines of input and store each line in the array 't'
	for i := 0; i < 4; i++ {
		var input string
		fmt.Scanln(&input)
		for j, char := range input {
			t[i][j] = char
		}
	}

	// Initialize counters for black and white cells
	black := 0
	white := 0
	// Initialize a flag to indicate if the grid is correct
	correct := false

	// Iterate through the 3x3 grid (the first 3 rows and columns)
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			// Count the number of black cells ('#') in the 2x2 block
			if t[i][j] == '#' {
				black++
			} else {
				white++
			}

			// Check the right cell in the 2x2 block
			if t[i][j+1] == '#' {
				black++
			} else {
				white++
			}

			// Check the bottom cell in the 2x2 block
			if t[i+1][j] == '#' {
				black++
			} else {
				white++
			}

			// Check the bottom right cell in the 2x2 block
			if t[i+1][j+1] == '#' {
				black++
			} else {
				white++
			}

			// Check if the current 2x2 block is valid (all black or all white)
			if black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4 {
				correct = true // Mark as correct if the condition is met
				break
			}

			// Reset counters for the next 2x2 block
			black = 0
			white = 0
		}
		if correct {
			break
		}
	}

	// Output the result based on whether a correct block was found
	if correct {
		fmt.Println("YES") // Print 'YES' if a valid block was found
	} else {
		fmt.Println("NO")  // Print 'NO' if no valid block was found
	}
}

// <END-OF-CODE>
