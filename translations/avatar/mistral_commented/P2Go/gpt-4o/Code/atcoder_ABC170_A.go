package main

import (
	"fmt"
	"strings"
)

func main() {
	// Read a line of input from the standard input
	var input string
	fmt.Scanln(&input)

	// Split the input string into a slice of strings and convert each to an integer
	nums := strings.Fields(input)
	a := make([]int, len(nums))
	for i, s := range nums {
		fmt.Sscan(s, &a[i])
	}

	// Iterate over the elements of the slice a
	for index, value := range a {
		// Check if the current value is equal to zero
		if value == 0 {
			// Print the index of the first zero (1-based index)
			fmt.Println(index + 1)
			// Terminate the loop using the break statement
			break
		}
	}
}

// <END-OF-CODE>
