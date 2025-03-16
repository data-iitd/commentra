package main

import (
	"fmt"
	"sort"
)

// Define a function named 'run' that takes two arguments 's' and 't'
func run(s, t string) string {
	// Create a map to count the occurrences of each character in string 's'
	ss := make(map[rune]int)
	for _, char := range s {
		ss[char]++
	}

	// Create a map to count the occurrences of each character in string 't'
	tt := make(map[rune]int)
	for _, char := range t {
		tt[char]++
	}

	// Convert the map values to a slice and sort them
	var ssValues, ttValues []int
	for _, value := range ss {
		ssValues = append(ssValues, value)
	}
	for _, value := range tt {
		ttValues = append(ttValues, value)
	}
	sort.Ints(ssValues)
	sort.Ints(ttValues)

	// Compare the sorted slices of occurrences of characters in strings 's' and 't'
	// If they are equal, then the strings have the same frequency distribution of characters
	// and thus are identical, so return 'Yes'
	// Otherwise, return 'No'
	if equal(ssValues, ttValues) {
		return "Yes"
	} else {
		return "No"
	}
}

// Define a function named 'main' that takes no arguments
func main() {
	// Taking input strings 's' and 't' from the user
	var s, t string
	fmt.Scan(&s, &t)

	// Calling the 'run' function with strings 's' and 't' as arguments and printing the result
	fmt.Println(run(s, t))
}

// Helper function to check if two slices are equal
func equal(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}
