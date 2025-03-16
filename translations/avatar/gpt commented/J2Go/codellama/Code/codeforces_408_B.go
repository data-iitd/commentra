package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	s := bufio.NewScanner(os.Stdin)

	// Read two strings from the input
	s1 := s.Text()
	s2 := s.Text()

	// Validate the input strings; if invalid, print -1 and exit
	if isValid(s1, s2) == false {
		fmt.Println(-1)
	} else {
		// Create HashMaps to count the frequency of characters in both strings
		m1 := make(map[rune]int)
		m2 := make(map[rune]int)

		// Count the frequency of each character in the first string
		for _, c := range s1 {
			if m1[c] > 0 {
				m1[c]++
			} else {
				m1[c] = 1
			}
		}

		// Count the frequency of each character in the second string
		for _, c := range s2 {
			if m2[c] > 0 {
				m2[c]++
			} else {
				m2[c] = 1
			}
		}

		// Initialize a variable to hold the result
		ans := 0
		// Create a HashSet to track unique characters from the second string
		hs := make(map[rune]bool)

		// Calculate the minimum frequency of each character present in both strings
		for _, c := range s2 {
			if !hs[c] {
				hs[c] = true
				x1 := m1[c] // Frequency in the first string
				x2 := m2[c] // Frequency in the second string
				x1 = int(math.Min(float64(x1), float64(x2))) // Take the minimum frequency
				ans += x1 // Add to the result
			}
		}
		// Print the final result
		fmt.Println(ans)
	}
}

// Method to check if the characters in s2 are all present in s1
func isValid(s1, s2 string) bool {
	n1 := len(s1)
	n2 := len(s2)
	// Create a HashMap to store characters from the first string
	map := make(map[rune]bool)

	// Add all characters from the first string to the map
	for _, c := range s1 {
		map[c] = true
	}

	// Check if all characters in the second string are present in the first string
	for _, c := range s2 {
		if !map[c] {
			return false
		}
	}
	return true // All characters are valid
}

