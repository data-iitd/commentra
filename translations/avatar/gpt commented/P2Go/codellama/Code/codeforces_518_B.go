package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read two strings from input
	s, t := input()

	// Initialize dictionaries to store frequency counts of characters in both strings
	freqs := make(map[string]int)
	freqt := make(map[string]int)

	// Initialize counters for matching characters
	yay, whoops := 0, 0

	// Count the frequency of each character in the first string 's'
	for _, letra := range s {
		if _, ok := freqs[string(letra)]; ok {
			freqs[string(letra)] += 1 // Increment count if character already exists
		} else {
			freqs[string(letra)] = 1 // Initialize count if character is new
		}
	}

	// Count the frequency of each character in the second string 't'
	for _, letra := range t {
		if _, ok := freqt[string(letra)]; ok {
			freqt[string(letra)] += 1 // Increment count if character already exists
		} else {
			freqt[string(letra)] = 1 // Initialize count if character is new
		}
	}

	// Compare character frequencies from both strings to count exact matches
	for letra, count := range freqs {
		for i := 0; i < count; i++ {
			if _, ok := freqt[letra]; ok {
				yay += 1 // Increment the count of exact matches
				freqt[letra] -= 1 // Decrease the count in the second string
			}
		}
	}

	// Compare remaining characters for case-insensitive matches
	for letra, count := range freqs {
		for i := 0; i < count; i++ {
			// Check for a lowercase letter in 's' and its uppercase counterpart in 't'
			if strings.ToLower(letra) == letra && strings.ToUpper(letra) == letra && freqt[strings.ToUpper(letra)] > 0 {
				whoops += 1 // Increment the count of case-insensitive matches
				freqt[strings.ToUpper(letra)] -= 1 // Decrease the count in the second string
			}
			// Check for an uppercase letter in 's' and its lowercase counterpart in 't'
			if strings.ToUpper(letra) == letra && strings.ToLower(letra) == letra && freqt[strings.ToLower(letra)] > 0 {
				whoops += 1 // Increment the count of case-insensitive matches
				freqt[strings.ToLower(letra)] -= 1 // Decrease the count in the second string
			}
		}
	}

	// Print the results: number of exact matches and case-insensitive matches
	fmt.Println(yay, whoops)
}

func input() (string, string) {
	var s, t string
	fmt.Scan(&s, &t)
	return s, t
}

// 