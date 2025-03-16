package main

import (
	"fmt"
)

func main() {
	var t [4][4]rune // Initialize a 4x4 array to store the input data.

	// Loop to take input and store it in the array t.
	for i := 0; i < 4; i++ {
		var input string
		fmt.Scan(&input) // Take input as a string.
		for j, char := range input {
			t[i][j] = char // Store each character in the array.
		}
	}

	black := 0  // Initialize the count of black cells to 0.
	white := 0  // Initialize the count of white cells to 0.
	correct := 0 // Initialize the correct flag to 0.

	// Nested loop to iterate over the 3x3 grid formed by the first 3 rows and columns of t.
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			// Count the number of black and white cells in the current 2x2 subgrid.
			black = 0
			white = 0
			for di := 0; di <= 1; di++ {
				for dj := 0; dj <= 1; dj++ {
					if t[i+di][j+dj] == '#' {
						black++
					} else {
						white++
					}
				}
			}

			// Check if the counts of black and white cells meet any of the specified conditions.
			if black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4 {
				correct = 1
				break // If conditions are met, set correct to 1 and break out of the loop.
			}
		}
		if correct == 1 {
			break
		}
	}

	// Print 'YES' if correct is 1, otherwise print 'NO'.
	if correct == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
