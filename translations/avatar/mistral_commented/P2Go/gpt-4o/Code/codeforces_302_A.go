package main

import (
	"fmt"
	"strings"
)

func main() {
	// Define the number of strings n and the number of operations m
	var n, m int
	fmt.Scan(&n, &m)

	// Calculate the number of '-' symbols in the input string
	var inputString string
	fmt.Scan(&inputString)
	sa := strings.Count(inputString, "-")

	// Ensure the number of '-' symbols is valid
	if sa > n {
		sa = n - sa
	}

	// Initialize a slice to store the results of each operation
	var ss []string

	// Perform each operation as described in the problem statement
	for i := 0; i < m; i++ {
		// Read two integers a and b from the input
		var a, b int
		fmt.Scan(&a, &b)

		// Calculate the difference between b and a
		b -= a

		// Check if the difference is valid based on the number of '-' symbols
		if b%2 == 0 || b > sa<<1 {
			// If the difference is valid, add '1' to the result slice
			ss = append(ss, "1\n")
		} else {
			// If the difference is not valid, add '0' to the result slice
			ss = append(ss, "0\n")
		}
	}

	// Print the final result by joining all the strings in the 'ss' slice with an empty string as separator
	fmt.Print(strings.Join(ss, ""))
}

// <END-OF-CODE>
