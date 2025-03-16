package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	// Create a new Scanner to read from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the first line of input from stdin
	s1, _ := reader.ReadString('\n')

	// Read the second line of input from stdin
	s2, _ := reader.ReadString('\n')

	// Remove the newline character
	s1 = s1[:len(s1)-1]
	s2 = s2[:len(s2)-1]

	// Check if the characters in s2 are all present in s1
	if isValid(s1, s2) {
		// Create a map to store the frequency of characters in s1
		m1 := make(map[rune]int)

		// Create a map to store the frequency of characters in s2
		m2 := make(map[rune]int)

		// Count the frequency of each character in s1
		for _, c := range s1 {
			m1[c]++
		}

		// Count the frequency of each character in s2
		for _, c := range s2 {
			m2[c]++
		}

		// Create a slice to store the characters in s2
		chars := make([]rune, 0)

		// Add all characters in s2 to the slice
		for c := range m2 {
			chars = append(chars, c)
		}

		// Sort the slice
		sort.Slice(chars, func(i, j int) bool {
			return m2[chars[i]] < m2[chars[j]]
		})

		// Initialize a variable to hold the result
		ans := 0

		// Calculate the minimum frequency of each character present in both strings
		for _, c := range chars {
			x1 := m1[c] // Frequency in s1
			x2 := m2[c] // Frequency in s2
			x1 = min(x1, x2) // Take the minimum frequency
			ans += x1 // Add to the result
		}

		// Print the final result
		fmt.Println(ans)
	} else {
		// Print -1 if the characters in s2 are not all present in s1
		fmt.Println(-1)
	}
}

// Method to check if the characters in s2 are all present in s1
func isValid(s1 string, s2 string) bool {
	// Create a map to store characters from s1
	m := make(map[rune]bool)

	// Add all characters from s1 to the map
	for _, c := range s1 {
		m[c] = true
	}

	// Check if all characters in s2 are present in s1
	for _, c := range s2 {
		if!m[c] {
			return false
		}
	}

	return true
}

// Method to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

