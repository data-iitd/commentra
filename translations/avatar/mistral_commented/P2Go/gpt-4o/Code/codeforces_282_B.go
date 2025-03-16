package main

import (
	"fmt"
	"strings"
)

func main() {
	// Take the first line as an input
	var firstline int
	fmt.Scan(&firstline)

	// Initialize total and memory slice
	total := 0
	memory := []string{}

	// Loop through the given number of lines
	for x := 0; x < firstline; x++ {
		// Take two integers as input, A and G
		var A, G int
		fmt.Scan(&A, &G)

		// Check if adding A to the total memory usage is within the limit
		if total+A <= 500 {
			// If yes, add A to the total and append 'A' to the memory slice
			total += A
			memory = append(memory, "A")
		} else {
			// If no, subtract G from the total and append 'G' to the memory slice
			total -= G
			memory = append(memory, "G")
		}
	}

	// Print the final memory state
	fmt.Println(strings.Join(memory, ""))
}

// <END-OF-CODE>
