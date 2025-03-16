package main

import (
	"fmt"
	"strings"
)

// Function to count occurrences of each character in a string
func countOccurrences(s string) map[rune]int {
	counts := make(map[rune]int)
	for _, char := range s {
		counts[char]++
	}
	return counts
}

// Function to find the solution
func solution() {
	// Read the first line and count the number of occurrences of each color
	var line string
	fmt.Scanln(&line)
	boughtCount := countOccurrences(line)

	// Read the second line and count the number of occurrences of each color
	fmt.Scanln(&line)
	madeCount := countOccurrences(line)

	// Initialize result to 0
	res := 0

	// Iterate through each color in madeCount
	for color, made := range madeCount {
		// Check if the color is present in boughtCount
		if _, exists := boughtCount[color]; !exists {
			// If not, print -1 and exit the function
			fmt.Println(-1)
			return
		}

		// Update the result by adding the minimum of bought and made counts
		res += min(boughtCount[color], made)
	}

	// Print the result
	fmt.Println(res)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Main function to run the solution function for multiple test cases
func main() {
	// Read the number of test cases
	var t int
	fmt.Scan(&t)

	// Run the solution function for each test case
	for i := 0; i < t; i++ {
		solution()
	}
}

// <END-OF-CODE>
