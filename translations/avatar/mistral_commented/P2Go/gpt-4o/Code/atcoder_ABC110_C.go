package main

import (
	"fmt"
	"sort"
)

// Function to count the occurrences of each character in a string
func countCharacters(s string) map[rune]int {
	counts := make(map[rune]int)
	for _, char := range s {
		counts[char]++
	}
	return counts
}

// Function to compare the frequency distribution of characters in two strings
func run(s, t string) string {
	ss := countCharacters(s)
	tt := countCharacters(t)

	// Create slices to hold the counts
	sCounts := make([]int, 0, len(ss))
	tCounts := make([]int, 0, len(tt))

	// Fill the slices with the counts
	for _, count := range ss {
		sCounts = append(sCounts, count)
	}
	for _, count := range tt {
		tCounts = append(tCounts, count)
	}

	// Sort the slices
	sort.Ints(sCounts)
	sort.Ints(tCounts)

	// Compare the sorted slices
	if len(sCounts) != len(tCounts) {
		return "No"
	}
	for i := range sCounts {
		if sCounts[i] != tCounts[i] {
			return "No"
		}
	}
	return "Yes"
}

// Main function to take input and call the run function
func main() {
	var s, t string
	fmt.Scanln(&s)
	fmt.Scanln(&t)

	// Print the result of the run function
	fmt.Println(run(s, t))
}

// <END-OF-CODE>
