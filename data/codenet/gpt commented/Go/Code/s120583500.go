package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
	// Declare a variable to hold the input string
	var s string
	// Read input from the user
	fmt.Scan(&s)

	// Initialize a counter for consecutive valid characters and a slice to hold counts
	count := 0
	var counter []int

	// If the input string is empty, exit the function
	if s == "" {
		return
	}

	// Start the counter with an initial value of 0
	counter = append(counter, 0)
	// Split the input string into a slice of individual characters
	li := strings.Split(s, "")

	// Iterate over each character in the slice
	for _, s := range li {
		// Check if the character is one of the valid DNA bases
		if s == "A" || s == "C" || s == "G" || s == "T" {
			// Increment the count for consecutive valid characters
			count++
		} else {
			// If an invalid character is encountered, store the current count
			counter = append(counter, count)
			// Reset the count for the next sequence
			count = 0
		}
	}

	// Append the count of the last sequence of valid characters
	counter = append(counter, count)
	// Sort the counts to find the maximum consecutive valid characters
	sort.Ints(counter)
	// Print the maximum count of consecutive valid characters
	fmt.Println(counter[len(counter)-1])
}
