package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read the first line of input which indicates the number of iterations
	var firstline int
	fmt.Scan(&firstline)

	// Initialize total to keep track of the accumulated value
	total := 0

	// Create a slice to store the memory of actions taken
	memory := []string{}

	// Loop through the range defined by firstline
	for i := 0; i < firstline; i++ {
		// Read two integers A and G from input, separated by space
		var A, G int
		fmt.Scan(&A, &G)

		// Check if adding A to total does not exceed the limit of 500
		if total+A <= 500 {
			// If within limit, add A to total
			total += A
			// Record the action "A" in memory
			memory = append(memory, "A")
		} else {
			// If limit exceeded, subtract G from total
			total -= G
			// Record the action "G" in memory
			memory = append(memory, "G")
		}
	}

	// Print the sequence of actions taken as a single string
	fmt.Println(strings.Join(memory, ""))
}

// <END-OF-CODE>
