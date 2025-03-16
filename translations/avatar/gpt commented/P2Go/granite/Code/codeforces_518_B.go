
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Read two strings from input
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	t, _ := reader.ReadString('\n')

	// Initialize dictionaries to store frequency counts of characters in both strings
	freqs := make(map[string]int)
	freqt := make(map[string]int)

	// Initialize counters for matching characters
	yay, whoops := 0, 0

	// Count the frequency of each character in the first string's'
	for _, letra := range strings.Split(s, "") {
		freqs[letra]++
	}

	// Count the frequency of each character in the second string 't'
	for _, letra := range strings.Split(t, "") {
		freqt[letra]++
	}

	// Compare character frequencies from both strings to count exact matches
	for letra, count := range freqs {
		for count > 0 && freqt[letra] > 0 {
			yay++ // Increment the count of exact matches
			freqs[letra]-- // Decrease the count in the first string
			freqt[letra]-- // Decrease the count in the second string
		}
	}

	// Compare remaining characters for case-insensitive matches
	for letra, count := range freqs {
		for count > 0 {
			// Check for a lowercase letter in's' and its uppercase counterpart in 't'
			if strings.ToLower(letra) == letra && strings.ToUpper(letra) == letra && freqt[strings.ToUpper(letra)] > 0 {
				whoops++ // Increment the count of case-insensitive matches
				freqs[letra]-- // Decrease the count in the first string
				freqt[strings.ToUpper(letra)]-- // Decrease the count in the second string
			// Check for an uppercase letter in's' and its lowercase counterpart in 't'
			} else if strings.ToLower(letra) == letra && strings.ToUpper(letra) == letra && freqt[strings.ToLower(letra)] > 0 {
				whoops++ // Increment the count of case-insensitive matches
				freqs[letra]-- // Decrease the count in the first string
				freqt[strings.ToLower(letra)]-- // Decrease the count in the second string
			} else {
				break // Exit the loop if no more matches can be found
			}
		}
	}

	// Print the results: number of exact matches and case-insensitive matches
	fmt.Println(yay, whoops)
}
