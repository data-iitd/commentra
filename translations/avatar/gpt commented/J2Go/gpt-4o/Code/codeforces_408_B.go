package main

import (
	"fmt"
)

func main() {
	var s1, s2 string
	// Read two strings from the input
	fmt.Scan(&s1, &s2)

	// Validate the input strings; if invalid, print -1 and exit
	if !isValid(s1, s2) {
		fmt.Println(-1)
		return
	}

	// Create maps to count the frequency of characters in both strings
	m1 := make(map[rune]int)
	m2 := make(map[rune]int)

	// Count the frequency of each character in the first string
	for _, c := range s1 {
		m1[c]++
	}

	// Count the frequency of each character in the second string
	for _, c := range s2 {
		m2[c]++
	}

	// Initialize a variable to hold the result
	ans := 0
	// Create a map to track unique characters from the second string
	hs := make(map[rune]bool)

	// Calculate the minimum frequency of each character present in both strings
	for _, c := range s2 {
		if !hs[c] {
			hs[c] = true
			x1 := m1[c] // Frequency in the first string
			x2 := m2[c] // Frequency in the second string
			if x1 < x2 {
				ans += x1 // Take the minimum frequency
			} else {
				ans += x2
			}
		}
	}
	// Print the final result
	fmt.Println(ans)
}

// Method to check if the characters in s2 are all present in s1
func isValid(s1, s2 string) bool {
	// Create a map to store characters from the first string
	mapChars := make(map[rune]bool)

	// Add all characters from the first string to the map
	for _, c := range s1 {
		mapChars[c] = true
	}

	// Check if all characters in the second string are present in the first string
	for _, c := range s2 {
		if !mapChars[c] {
			return false
		}
	}
	return true // All characters are valid
}

// <END-OF-CODE>
