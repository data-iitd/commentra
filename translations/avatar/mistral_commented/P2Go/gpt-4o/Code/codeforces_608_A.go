package main

import (
	"fmt"
)

func main() {
	var n, s int
	// Reading the number of test cases and the target sum
	fmt.Scan(&n, &s)

	c := 0 // Initializing c to 0

	// Iterating through the test cases
	for i := 0; i < n; i++ {
		var f, t int
		// Reading the start and end time of each activity
		fmt.Scan(&f, &t)

		// Calculating the difference
		x := t - (s - f)

		// Updating c with the maximum value of x
		if x > c {
			c = x
		}
	}

	// Printing the final answer
	fmt.Println(s + c)
}

// <END-OF-CODE>
