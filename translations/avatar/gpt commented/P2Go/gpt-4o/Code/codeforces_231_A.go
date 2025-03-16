package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read an integer input which represents the number of lists to process
	var n int
	fmt.Scan(&n)

	// Initialize a counter to keep track of lists with a sum greater than 1
	c := 0

	// Loop through the range of n to process each list
	for i := 0; i < n; i++ {
		// Read a line of input
		var input string
		fmt.Scan(&input)

		// Split the input string into individual string elements
		parts := strings.Split(input, " ")

		// Initialize a sum variable
		sum := 0

		// Convert each string element to an integer and calculate the sum
		for _, part := range parts {
			var num int
			fmt.Sscan(part, &num)
			sum += num
		}

		// Check if the sum of the current list is greater than 1
		if sum > 1 {
			// Increment the counter if the condition is met
			c++
		}
	}

	// Print the final count of lists that had a sum greater than 1
	fmt.Println(c)
}

// <END-OF-CODE>
