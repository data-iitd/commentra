package main

import (
	"fmt"
)

func main() {
	var t [4][4]rune // Initialize a 4x4 array to store the input characters

	// Loop through 4 iterations to get input strings from user
	for i := 0; i < 4; i++ {
		var input string
		fmt.Scan(&input) // Read input string
		for j, char := range input {
			t[i][j] = char // Store each character in the array
		}
	}

	black := 0 // Initialize black and white counters to 0
	white := 0
	correct := 0

	// Loop through the first 3 rows of the 4x4 grid
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if t[i][j] == '#' { // If current cell contains '#', increment 'black' counter
				black++
			} else { // If current cell contains '.', increment 'white' counter
				white++
			}

			// Check the neighboring cells and increment 'black' or 'white' counter accordingly
			if t[i][j+1] == '#' {
				black++
			} else {
				white++
			}

			if t[i+1][j] == '#' {
				black++
			} else {
				white++
			}

			if t[i+1][j+1] == '#' {
				black++
			} else {
				white++
			}

			// Check the current cell and its neighbors for winning conditions
			if black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4 {
				correct = 1 // If a winning condition is met, set 'correct' to 1 and break out of the loop
				break
			}

			// Reset black and white counters for the next iteration of the inner loop
			black = 0
			white = 0
		}
		if correct == 1 {
			break
		}
	}

	if correct == 1 { // If 'correct' is set to 1, print 'YES'
		fmt.Println("YES")
	} else { // If 'correct' is not set to 1, print 'NO'
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
