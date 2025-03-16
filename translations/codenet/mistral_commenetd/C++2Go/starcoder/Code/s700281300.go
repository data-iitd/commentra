
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Function to reverse a string
func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

// Function to find all possible combinations of a string
func findCombinations(s string) []string {
	var combinations []string
	for i := 1; i < len(s); i++ {
		combinations = append(combinations, s[:i])
		combinations = append(combinations, reverse(s[:i]))
		combinations = append(combinations, s[i:])
		combinations = append(combinations, reverse(s[i:]))
	}
	return combinations
}

// Function to find the number of unique substrings
func findUniqueSubstrings(s string) int {
	// Create a set to store unique substrings
	uniqueSubstrings := make(map[string]bool)

	// Iterate through each substring of the string
	for i := 1; i < len(s); i++ {
		// Find all possible combinations of the substring
		combinations := findCombinations(s[:i])
		combinations = append(combinations, findCombinations(s[i:])...)

		// Insert all possible combinations of the substrings and their reversed versions into the set
		for _, combination := range combinations {
			uniqueSubstrings[combination] = true
		}
	}

	// Return the size of the set, which represents the number of unique substrings
	return len(uniqueSubstrings)
}

// Main function starts here
func main() {
	var n int
	var s string

	// Read the number of strings from the standard input
<<<<<<< HEAD
	fmt.Scanln(&n)
=======
	fmt.Scanf("%d\n", &n)
>>>>>>> 98c87cb78a (data updated)

	// Iterate through each string
	for i := 0; i < n; i++ {
		// Read the string from the standard input
<<<<<<< HEAD
		fmt.Scanln(&s)
=======
		fmt.Scanf("%s\n", &s)
>>>>>>> 98c87cb78a (data updated)

		// Find the number of unique substrings
		uniqueSubstrings := findUniqueSubstrings(s)

		// Print the size of the set, which represents the number of unique substrings
<<<<<<< HEAD
		fmt.Println(uniqueSubstrings)
=======
		fmt.Printf("%d\n", uniqueSubstrings)
>>>>>>> 98c87cb78a (data updated)
	}
}

