
package main

import (
	"fmt"
	"regexp"
)

func main() {
	// Read an integer input which represents the maximum allowed length for sentences
	var n int
	fmt.Scan(&n)

	// Initialize the answer counter and the sum of lengths of sentences
	ans, sumL := 1, 0

	// Split the input text into sentences based on punctuation marks (., ?, !)
	sentences := regexp.MustCompile("[.?!]").Split(input(), -1)

	// Iterate over the sentences
	for _, s := range sentences {
		s = s + "." // Strip whitespace and add a period to the end of the sentence
		L := len(s) // Calculate the length of the current sentence

		// Check if the length of the sentence is greater than 1 (to avoid empty sentences)
		if L > 1 {
			// If the length of the sentence exceeds the maximum allowed length, print "Impossible" and exit
			if L > n {
				fmt.Println("Impossible")
				return
			}

			// Check if adding the current sentence length to the sum exceeds the maximum allowed length
			if sumL+L+(sumL > 0) > n {
				ans++ // Increment the answer counter for a new line
				sumL = L // Reset the sum of lengths to the current sentence length
			} else {
				// Update the sum of lengths by adding the current sentence length
				sumL = sumL + L + (sumL > 0) // Add 1 if there was a previous sentence (to account for space)
			}
		}
	}

	// Print the total number of lines needed
	fmt.Println(ans)
}

// 