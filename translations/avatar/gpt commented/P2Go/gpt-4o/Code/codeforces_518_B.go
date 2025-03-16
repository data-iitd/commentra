package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scanln(&s)
	fmt.Scanln(&t)

	// Initialize maps to store frequency counts of characters in both strings
	freqs := make(map[rune]int)
	freqt := make(map[rune]int)

	// Initialize counters for matching characters
	yay, whoops := 0, 0

	// Count the frequency of each character in the first string 's'
	for _, letra := range s {
		freqs[letra]++
	}

	// Count the frequency of each character in the second string 't'
	for _, letra := range t {
		freqt[letra]++
	}

	// Compare character frequencies from both strings to count exact matches
	for letra := range freqs {
		for freqs[letra] > 0 && freqt[letra] > 0 {
			yay++ // Increment the count of exact matches
			freqs[letra]-- // Decrease the count in the first string
			freqt[letra]-- // Decrease the count in the second string
		}
	}

	// Compare remaining characters for case-insensitive matches
	for letra := range freqs {
		for freqs[letra] > 0 {
			// Check for a lowercase letter in 's' and its uppercase counterpart in 't'
			if letra >= 'a' && letra <= 'z' {
				if freqt[letra+('A'-'a')] > 0 {
					whoops++ // Increment the count of case-insensitive matches
					freqs[letra]-- // Decrease the count in the first string
					freqt[letra+('A'-'a')]-- // Decrease the count in the second string
				} else {
					break // Exit the loop if no more matches can be found
				}
			} else if letra >= 'A' && letra <= 'Z' { // Check for an uppercase letter in 's'
				if freqt[letra+('a'-'A')] > 0 {
					whoops++ // Increment the count of case-insensitive matches
					freqs[letra]-- // Decrease the count in the first string
					freqt[letra+('a'-'A')]-- // Decrease the count in the second string
				} else {
					break // Exit the loop if no more matches can be found
				}
			} else {
				break // Exit the loop if no more matches can be found
			}
		}
	}

	// Print the results: number of exact matches and case-insensitive matches
	fmt.Println(yay, whoops)
}

// <END-OF-CODE>
