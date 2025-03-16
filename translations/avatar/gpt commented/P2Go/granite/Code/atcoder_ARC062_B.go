
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read input and convert it into a list of characters
	s := make([]byte, 0)
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		s = scanner.Bytes()
	}

	// Initialize counters for 'g' and 'p' occurrences, and the score
	num_g, num_p := 0, 0
	score := 0

	// Iterate through each character in the input list
	for _, x := range s {
		// Check if the character is 'g'
		if x == 'g' {
			// If there are more 'g's than 'p's, increase the score and count 'p'
			if num_g-num_p > 0 {
				score += 1 // Increase score for 'g'
				num_p += 1 // Increment the count of 'p's
			} else {
				// If not, just increment the count of 'g's
				num_g += 1 // Increment the count of 'g's
			}
		}

		// Check if the character is 'p'
		if x == 'p' {
			// If there are more 'g's than 'p's, just count 'p'
			if num_g-num_p > 0 {
				num_p += 1 // Increment the count of 'p's
			} else {
				// If not, decrease the score and increment the count of 'g's
				score -= 1 // Decrease score for 'p'
				num_g += 1 // Increment the count of 'g's
			}
		}
	}

	// Print the final score
	fmt.Println(score)
}
