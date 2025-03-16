package main

import (
	"fmt"
)

func main() {
	var s1, s2 string
	fmt.Scan(&s1, &s2) // Read first and second strings

	// Check if the strings are valid using the isValid function
	if !isValid(s1, s2) {
		fmt.Println(-1) // Print -1 if strings are not valid
		return
	}

	m1 := make(map[rune]int) // Create map for s1
	m2 := make(map[rune]int) // Create map for s2

	// Populate the map with the frequency of each character in s1
	for _, c := range s1 {
		m1[c]++
	}

	// Populate the map with the frequency of each character in s2
	for _, c := range s2 {
		m2[c]++
	}

	ans := 0 // Initialize answer variable
	hs := make(map[rune]bool) // Create map to track processed characters

	// Iterate over the characters of s2
	for _, c := range s2 {
		if !hs[c] {
			hs[c] = true // Mark character as processed
			x1 := m1[c]  // Get frequency of character in s1
			x2 := m2[c]  // Get frequency of character in s2
			x1 = min(x1, x2) // Calculate minimum frequency
			ans += x1 // Add minimum frequency to answer
		}
	}

	fmt.Println(ans) // Print the final answer
}

// Function to check if s1 is a valid substring of s2
func isValid(s1, s2 string) bool {
	mapChars := make(map[rune]bool)

	// Populate the map with characters from s1
	for _, c := range s1 {
		mapChars[c] = true
	}

	// Check if all characters of s1 are present in s2
	for _, c := range s2 {
		if !mapChars[c] {
			return false
		}
	}

	return true
}

// Helper function to get the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
