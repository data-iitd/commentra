package main

import (
	"fmt"
	"strings"
)

func main() {
	var firstline int
	fmt.Scan(&firstline) // Read the first line of input, which determines the number of iterations
	total := 0           // Initialize a variable to keep track of the total sum
	memory := []string{} // Initialize an empty slice to store the decisions

	// Loop through the range of firstline
	for i := 0; i < firstline; i++ {
		var A, G int
		fmt.Scan(&A, &G) // Read two integers from a single line of input
		if total+A <= 500 { // Check if adding A to total would not exceed 500
			total += A      // Add A to total
			memory = append(memory, "A") // Append "A" to memory
		} else {
			total -= G      // Subtract G from total
			memory = append(memory, "G") // Append "G" to memory
		}
	}

	// Join the elements of memory into a single string and print it
	fmt.Println(strings.Join(memory, ""))
}

// <END-OF-CODE>
