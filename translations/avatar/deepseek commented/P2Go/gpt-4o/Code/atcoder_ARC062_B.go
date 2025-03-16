package main

import (
	"fmt"
)

func main() {
	var input string
	fmt.Scan(&input) // Read input string
	s := []rune(input) // Convert the input string into a slice of runes
	numG, numP := 0, 0 // Initialize counters for 'g' and 'p' characters
	score := 0 // Initialize the score variable to 0

	// Iterate over each character in the slice
	for _, x := range s {
		if x == 'g' {
			// Check if the number of 'g' characters exceeds the number of 'p' characters
			if numG-numP > 0 {
				score++ // Increment the score and the count of 'p' characters
				numP++
			} else {
				// Keep the score unchanged and increment the count of 'g' characters
				numG++
			}
		} else if x == 'p' {
			// Check if the number of 'g' characters exceeds the number of 'p' characters
			if numG-numP > 0 {
				// Keep the score unchanged and increment the count of 'p' characters
				numP++
			} else {
				score-- // Decrement the score and increment the count of 'g' characters
				numG++
			}
		}
	}

	fmt.Println(score) // Print the final score
}

// <END-OF-CODE>
