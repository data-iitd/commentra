package main

import (
	"fmt"
)

func main() {
	// Create a variable to read input from the console
	var n, k, l, c int
	c = 1

	// Read the number of elements (n) and the threshold (k)
	fmt.Scan(&n, &k)

	// Loop through each element to count consecutive occurrences
	for i := 0; i < n; i++ {
		var a int
		// Read the next integer from input
		fmt.Scan(&a)

		// Check if the current number is the same as the last one
		if a == l {
			c += 1 // Increment the count of consecutive occurrences
		} else {
			c = 1 // Reset the count if the number changes
		}

		// Update the last number to the current one
		l = a
	}

	// Check if the count of consecutive numbers plus k exceeds n
	if c+k > n {
		// If true, print the number of elements that are not part of the consecutive sequence
		fmt.Println(n - c)
	} else {
		// Otherwise, print -1 indicating the condition is not met
		fmt.Println(-1)
	}
}

// <END-OF-CODE>
