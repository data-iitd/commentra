package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	s := []rune(input) // Convert the input string into a list of characters
	var numG, numP int // Initialize counters for 'g' and 'p' characters
	score := 0 // Initialize the score variable to 0

	// Iterate over each character in the list
	for _, x := range s {
		if x == 'g' {
			// Check if the number of 'g' characters exceeds the number of 'p' characters
			if numG - numP > 0 {
				score += 1 // Increment the score and the count of 'p' characters
				numP += 1
			} else {
				score = score // Keep the score unchanged and increment the count of 'g' characters
				numG += 1
			}
		} else if x == 'p' {
			// Check if the number of 'g' characters exceeds the number of 'p' characters
			if numG - numP > 0 {
				score = score // Keep the score unchanged and increment the count of 'p' characters
				numP += 1
			} else {
				score -= 1 // Decrement the score and increment the count of 'g' characters
				numG += 1
			}
		}
	}

	fmt.Println(score) // Print the final score
}
