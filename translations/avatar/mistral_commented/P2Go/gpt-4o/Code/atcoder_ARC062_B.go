package main

import (
	"fmt"
)

func main() {
	// Initialize an empty slice to store input characters
	var s []rune
	var input string
	fmt.Scan(&input)
	s = []rune(input)

	// Initialize counters for 'g' and 'p' symbols
	numG, numP := 0, 0

	// Initialize score variable
	score := 0

	// Iterate through each character in the slice 's'
	for _, x := range s {
		// Check if current character is 'g'
		if x == 'g' {
			// Check if number of 'g' symbols is greater than number of 'p' symbols
			if numG-numP > 0 {
				// Increment score and number of 'p' symbols
				score++
				numP++
				// Comment: If there are more 'g' symbols than 'p' symbols, increment score and update number of 'p' symbols
			} else {
				// Do not change score and increment number of 'g' symbols
				numG++
				// Comment: If there are less or equal 'g' symbols than 'p' symbols, do not change score and update number of 'g' symbols
			}
		} else if x == 'p' { // Check if current character is 'p'
			// Check if number of 'g' symbols is greater than number of 'p' symbols
			if numG-numP > 0 {
				// Do not change score and increment number of 'p' symbols
				numP++
				// Comment: If there are more 'g' symbols than 'p' symbols, do not change score and update number of 'p' symbols
			} else {
				// Decrement score and increment number of 'g' symbols
				score--
				numG++
				// Comment: If there are less or equal 'g' symbols than 'p' symbols, decrement score and update number of 'g' symbols
			}
		}
	}

	// Print the final score
	fmt.Println(score)
	// Comment: After iterating through all characters in the slice 's', print the final score
}

// <END-OF-CODE>
