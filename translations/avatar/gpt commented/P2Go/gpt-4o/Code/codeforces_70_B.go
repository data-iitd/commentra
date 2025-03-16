package main

import (
	"fmt"
	"regexp"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n) // Read an integer input which represents the maximum allowed length for sentences

	ans, sumL := 1, 0

	// Read the input text
	var inputText string
	fmt.Scanln(&inputText)

	// Split the input text into sentences based on punctuation marks (., ?, !)
	re := regexp.MustCompile(`[.?!]`)
	sentences := re.Split(inputText, -1)

	for _, s := range sentences {
		s = strings.TrimSpace(s) + "." // Strip whitespace and add a period to the end of the sentence
		L := len(s)                     // Calculate the length of the current sentence

		// Check if the length of the sentence is greater than 1 (to avoid empty sentences)
		if L > 1 {
			// If the length of the sentence exceeds the maximum allowed length, print "Impossible" and exit
			if L > n {
				fmt.Println("Impossible")
				return
			}

			// Check if adding the current sentence length to the sum exceeds the maximum allowed length
			if sumL+L+(sumL > 0) > n {
				ans++   // Increment the answer counter for a new line
				sumL = L // Reset the sum of lengths to the current sentence length
			} else {
				// Update the sum of lengths by adding the current sentence length
				sumL = sumL + L + boolToInt(sumL > 0) // Add 1 if there was a previous sentence (to account for space)
			}
		}
	}

	// Print the total number of lines needed
	fmt.Println(ans)
}

// Helper function to convert a boolean to an integer (1 for true, 0 for false)
func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}
