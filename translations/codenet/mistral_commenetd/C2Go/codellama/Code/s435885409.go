package main

import (
	"fmt"
	"strings"
)

// Function to calculate the score for each inning
func calcScore() int {
	out := 0 // Initialize the number of outs to 0
	str := "" // Create a string to store the input string
	score := 0 // Initialize the score to 0
	base := 0 // Initialize the number of bases to 0

	// Loop through the three events in each inning
	for out < 3 {
		fmt.Print("Enter the event for this at bat (HIT, HOMERUN or OUT): ") // Ask for the event
		fmt.Scan(&str) // Read the event from the standard input

		// Check if the event is OUT
		if str == "OUT" {
			out++ // Increment the number of outs
		}
		// Check if the event is HIT
		else if str == "HIT" {
			// If there are already three bases, increment the score
			if base == 3 {
				score++
			}
			// If not, increment the number of bases
			else {
				base++
			}
		}
		// Check if the event is HOMERUN
		else if str == "HOMERUN" {
			score += (base + 1) // Add the number of bases and 1 to the score
			base = 0 // Reset the number of bases to 0
		}
	}

	// Return the score for this inning
	return score
}

// Main function to read the number of innings and call calcScore() for each inning
func main() {
	n := 0 // Initialize the number of innings to be read
	inning := 0 // Initialize the current inning number to 0

	// Read the number of innings from the standard input
	fmt.Print("Enter the number of innings: ")
	fmt.Scan(&n)

	// Loop through each inning and call calcScore() to calculate the score
	for inning < n {
		score := calcScore() // Call calcScore() to calculate the score for this inning
		fmt.Println(score) // Print the score for this inning
		inning++ // Increment the current inning number
	}

	// Return 0 to indicate successful execution
	return 0
}

