package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initialize an empty slice to store input characters
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')

	// Initialize counters for 'g' and 'p' symbols
	numG, numP := 0, 0

	// Initialize score variable
	score := 0

	// Iterate through each character in the slice 's'
	for _, x := range s {
		// Check if current character is 'g'
		if x == 'g' {
			// Check if number of 'g' symbols is greater than number of 'p' symbols
			if numG - numP > 0 {
				// Increment score and number of 'p' symbols
				score += 1
				numP += 1
			} else {
				// Do not change score and increment number of 'g' symbols
				numG += 1
			}
		}
		// Check if current character is 'p'
		else if x == 'p' {
			// Check if number of 'g' symbols is greater than number of 'p' symbols
			if numG - numP > 0 {
				// Do not change score and increment number of 'p' symbols
				numP += 1
			} else {
				// Decrement score and increment number of 'g' symbols
				score -= 1
				numG += 1
			}
		}
	}

	// Print the final score
	fmt.Println(score)
}

