package main

import (
	"fmt"
	"strings"
)

func main() {
	var s1, s2 string
	fmt.Scan(&s1, &s2) // Read the first and second strings from input

	if !isValid(s1, s2) { // Check if the given strings are valid
		fmt.Println(-1) // If not valid, print -1 and exit
		return
	}

	m1 := make(map[rune]int) // Create a map to store the frequency of characters in the first string
	m2 := make(map[rune]int) // Create a map to store the frequency of characters in the second string

	for _, c := range s1 { // Iterate through each character in the first string
		m1[c]++ // Increment the count of the character
	}

	for _, c := range s2 { // Iterate through each character in the second string
		m2[c]++ // Increment the count of the character
	}

	ans := 0 // Initialize the answer variable to 0
	hs := make(map[rune]struct{}) // Create a map to store unique characters in the second string

	for _, c := range s2 { // Iterate through each character in the second string
		if _, exists := hs[c]; !exists { // If the character is not already in the map, add it and compute the answer
			hs[c] = struct{}{}
			x1 := m1[c] // Get the count of the character in the first string
			x2 := m2[c] // Get the count of the character in the second string
			if x1 < x2 {
				ans += x1 // Add the minimum count to the answer
			} else {
				ans += x2
			}
		}
	}

	fmt.Println(ans) // Print the answer
}

func isValid(s1, s2 string) bool { // Check if the given strings are valid
	mapPresence := make(map[rune]bool) // Create a map to store the presence of characters in the first string

	for _, c := range s1 { // Iterate through each character in the first string
		mapPresence[c] = true // Mark the character as present in the map
	}

	for _, c := range s2 { // Iterate through each character in the second string
		if !mapPresence[c] { // If the character is not present in the first string, return false
			return false
		}
	}

	return true // If all characters in the second string are present in the first string, return true
}

// <END-OF-CODE>
