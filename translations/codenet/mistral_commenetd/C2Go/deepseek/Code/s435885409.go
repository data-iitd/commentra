package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Function to calculate the score for each inning
func calcScore() int {
	out := 0 // Initialize the number of outs to 0
	score := 0 // Initialize the score to 0
	base := 0 // Initialize the number of bases to 0

	// Loop through the three events in each inning
	for out < 3 {
		reader := bufio.NewReader(os.Stdin)
		fmt.Print("Enter the event for this at bat (HIT, HOMERUN or OUT): ")
		event, _ := reader.ReadString('\n')
		event = strings.TrimSpace(event)

		// Check if the event is OUT
		if event == "OUT" {
			out++ // Increment the number of outs
		}
		// Check if the event is HIT
		else if event == "HIT" {
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
		else if event == "HOMERUN" {
			score += (base + 1) // Add the number of bases and 1 to the score
			base = 0 // Reset the number of bases to 0
		}
	}

	// Return the score for this inning
	return score
}

// Main function to read the number of innings and call calcScore() for each inning
func main() {
	var n int // Initialize the number of innings to be read

	// Read the number of innings from the standard input
	fmt.Print("Enter the number of innings: ")
	fmt.Scanln(&n)

	// Loop through each inning and call calcScore() to calculate the score
	for inning := 0; inning < n; inning++ {
		score := calcScore() // Call calcScore() to calculate the score for this inning
		fmt.Println(score) // Print the score for this inning
	}
}

