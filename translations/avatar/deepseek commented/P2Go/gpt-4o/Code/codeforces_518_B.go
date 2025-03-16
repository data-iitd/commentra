package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scan(&s)
	fmt.Scan(&t)

	freqs := make(map[rune]int) // Dictionary to store frequency of characters in s
	freqt := make(map[rune]int) // Dictionary to store frequency of characters in t
	yay, whoops := 0, 0          // Initializing counters for yay and whoops

	// Populating the frequency dictionaries
	for _, letra := range s {
		freqs[letra]++
	}

	for _, letra := range t {
		freqt[letra]++
	}

	// Counting yay by matching characters in freqs and freqt
	for letra := range freqs {
		for freqs[letra] > 0 && freqt[letra] > 0 {
			yay++ // Incrementing yay if characters match
			freqs[letra]-- // Decrementing the count in freqs
			freqt[letra]-- // Decrementing the count in freqt
		}
	}

	// Counting whoops by transforming characters to match
	for letra := range freqs {
		for freqs[letra] > 0 {
			if letra >= 'a' && letra <= 'z' && freqt[unicode.ToUpper(letra)] > 0 {
				whoops++ // Incrementing whoops if transformation is possible
				freqs[letra]-- // Decrementing the count in freqs
				freqt[unicode.ToUpper(letra)]-- // Decrementing the count in freqt
			} else if letra >= 'A' && letra <= 'Z' && freqt[unicode.ToLower(letra)] > 0 {
				whoops++ // Incrementing whoops if transformation is possible
				freqs[letra]-- // Decrementing the count in freqs
				freqt[unicode.ToLower(letra)]-- // Decrementing the count in freqt
			} else {
				break // Breaking the loop if no more transformations are possible
			}
		}
	}

	fmt.Println(yay, whoops) // Printing the final counts of yay and whoops
}

// <END-OF-CODE>
