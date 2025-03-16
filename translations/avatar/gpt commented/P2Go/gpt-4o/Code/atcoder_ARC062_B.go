package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read input and convert it into a slice of runes
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	s := []rune(input)

	// Initialize counters for 'g' and 'p' occurrences, and the score
	numG, numP := 0, 0
	score := 0

	// Iterate through each character in the input slice
	for _, x := range s {
		// Check if the character is 'g'
		if x == 'g' {
			// If there are more 'g's than 'p's, increase the score and count 'p'
			if numG-numP > 0 {
				score++  // Increase score for 'g'
				numP++   // Increment the count of 'p's
			} else {
				// If not, just increment the count of 'g's
				numG++  // Increment the count of 'g's
			}
		} else if x == 'p' { // Check if the character is 'p'
			// If there are more 'g's than 'p's, just count 'p'
			if numG-numP > 0 {
				numP++  // Increment the count of 'p's
			} else {
				// If not, decrease the score and increment the count of 'g's
				score--  // Decrease score for 'p'
				numG++   // Increment the count of 'g's
			}
		}
	}

	// Print the final score
	fmt.Println(score)
}

// <END-OF-CODE>
