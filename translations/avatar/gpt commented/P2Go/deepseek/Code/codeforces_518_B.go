package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read two strings from input
	s, _ := reader.ReadString('\n')
	t, _ := reader.ReadString('\n')
	
	// Initialize maps to store frequency counts of characters in both strings
	freqs := make(map[rune]int)
	freqt := make(map[rune]int)
	
	// Initialize counters for matching characters
	yay, whoops := 0, 0
	
	// Count the frequency of each character in the first string 's'
	for _, letra := range s {
		if _, exists := freqs[letra]; exists {
			freqs[letra] += 1  // Increment count if character already exists
		} else {
			freqs[letra] = 1    // Initialize count if character is new
		}
	}
	
	// Count the frequency of each character in the second string 't'
	for _, letra := range t {
		if _, exists := freqt[letra]; exists {
			freqt[letra] += 1  // Increment count if character already exists
		} else {
			freqt[letra] = 1    // Initialize count if character is new
		}
	}
	
	// Compare character frequencies from both strings to count exact matches
	for letra := range freqs {
		for freqs[letra] > 0 && freqt[letra] > 0 {
			yay += 1  // Increment the count of exact matches
			freqs[letra] -= 1  // Decrease the count in the first string
			freqt[letra] -= 1  // Decrease the count in the second string
		}
	}
	
	// Compare remaining characters for case-insensitive matches
	for letra := range freqs {
		for freqs[letra] > 0 {
			// Check for a lowercase letter in 's' and its uppercase counterpart in 't'
			if letra >= 'a' && letra <= 'z' && rune(letra - 32) in freqt && freqt[rune(letra - 32)] > 0 {
				whoops += 1  // Increment the count of case-insensitive matches
				freqs[letra] -= 1  // Decrease the count in the first string
				freqt[rune(letra - 32)] -= 1  // Decrease the count in the second string
			} else if letra >= 'A' && letra <= 'Z' && rune(letra + 32) in freqt && freqt[rune(letra + 32)] > 0 {
				// Check for an uppercase letter in 's' and its lowercase counterpart in 't'
				whoops += 1  // Increment the count of case-insensitive matches
				freqs[letra] -= 1  // Decrease the count in the first string
				freqt[rune(letra + 32)] -= 1  // Decrease the count in the second string
			} else {
				break  // Exit the loop if no more matches can be found
			}
		}
	}
	
	// Print the results: number of exact matches and case-insensitive matches
	fmt.Println(yay, whoops)
}
