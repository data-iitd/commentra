
package main

import (
	"fmt"
	"regexp"
	"strings"
)

func main() {
	// Take the maximum sentence length as input
	var n int
	fmt.Scan(&n)

	// Initialize variables to keep track of the number of sentences and their cumulative length
	ans, sumL := 1, 0

	// Take a string input and split it into sentences using the regular expression [.?!]
	s := strings.Split(strings.TrimSpace(fmt.Scan()), ".[.?!]")
	for _, s := range s {
		// Strip leading and trailing whitespace and add a period to the end of the sentence
		s = strings.TrimSpace(s) + "."
		// Calculate the length of the sentence
		L := len(s)

		// Check if the sentence length is greater than 1
		if L > 1 {
			// Check if the sentence length is greater than the maximum allowed length
			if L > n {
				// If the sentence is too long, print "Impossible" and exit
				fmt.Println("Impossible")
				return
			}

			// Check if adding the current sentence would exceed the maximum allowed length
			if sumL+L+(sumL > 0) > n {
				// If adding the sentence would exceed the maximum length, increment the sentence count
				ans++
				// Reset the cumulative length to the length of the current sentence
				sumL = L
			} else {
				// Otherwise, add the length of the current sentence to the cumulative length
				sumL = sumL + L + (sumL > 0)
			}
		}
	}

	// Print the total number of sentences
	fmt.Println(ans)
}

// 