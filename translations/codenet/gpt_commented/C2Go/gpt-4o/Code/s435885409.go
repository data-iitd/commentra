package main

import (
	"fmt"
	"strings"
)

// Function to calculate the score based on user input
func calcScore() int {
	out := 0            // Initialize the number of outs
	var str string      // Buffer to store user input
	score := 0         // Initialize the score
	base := 0          // Initialize the number of players on base

	// Loop until there are 3 outs
	for out < 3 {
		fmt.Scan(&str) // Read user input into str

		// Check if the input is "OUT"
		if strings.EqualFold(str, "OUT") {
			out++ // Increment the out count
		} 
		// Check if the input is "HIT"
		else if strings.EqualFold(str, "HIT") {
			// If all bases are occupied, score a point
			if base == 3 {
				score++ // Increment the score
			} else {
				base++ // Move a player to the next base
			}
		} 
		// Check if the input is "HOMERUN"
		else if strings.EqualFold(str, "HOMERUN") {
			score += (base + 1) // Score based on players on base plus the hitter
			base = 0           // Reset bases after a homerun
		}
	}

	// Return the calculated score
	return score
}

// Main function to execute the program
func main() {
	var n int // Variable to hold the number of innings
	inning := 0 // Initialize the inning count

	// Read the number of innings from user input
	fmt.Scan(&n)

	// Loop through the number of innings
	for inning < n {
		fmt.Println(calcScore()) // Calculate and print the score for each inning
		inning++ // Increment the inning count
	}
}

// <END-OF-CODE>
