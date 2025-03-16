
package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input which represents the maximum allowed length for sentences
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Initialize the answer counter and the sum of lengths of sentences
	ans, sumL := 1, 0

	// Split the input text into sentences based on punctuation marks (.,?,!)
	for _, s := range regexp.MustCompile("[.?!]").Split(bufio.NewReader(os.Stdin).Scan(), -1) {
		s = strings.TrimSpace(s) + "."  // Strip whitespace and add a period to the end of the sentence
		L := len(s)  // Calculate the length of the current sentence

		// Check if the length of the sentence is greater than 1 (to avoid empty sentences)
		if L > 1 {
			// If the length of the sentence exceeds the maximum allowed length, print "Impossible" and exit
			if L > n {
				fmt.Println("Impossible")
				return
			}

			// Check if adding the current sentence length to the sum exceeds the maximum allowed length
			if sumL+L+(sumL > 0) > n {
				ans++  // Increment the answer counter for a new line
				sumL = L  // Reset the sum of lengths to the current sentence length
			} else {
				// Update the sum of lengths by adding the current sentence length
				sumL = sumL + L + (sumL > 0)  // Add 1 if there was a previous sentence (to account for space)
			}
		}
	}

	// Print the total number of lines needed
	fmt.Println(ans)
}
