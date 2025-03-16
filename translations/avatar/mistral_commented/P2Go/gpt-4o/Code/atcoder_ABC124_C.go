package main

import (
	"fmt"
	"strings"
)

func main() {
	// Initialize an empty slice 's' by taking input from the user
	var input string
	fmt.Scan(&input)
	s := strings.Split(input, "")

	// Create two maps to count the frequency of '0' and '1' in the first and second half of the slice 's' respectively
	even := make(map[string]int)
	odd := make(map[string]int)

	mid := len(s) / 2
	for _, char := range s[:mid] {
		even[char]++
	}
	for _, char := range s[mid:] {
		odd[char]++
	}

	// Calculate the minimum difference
	minDiff := min(len(s)-(even["0"]+odd["1"]), len(s)-(even["1"]+odd["0"]))
	fmt.Println(minDiff)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
