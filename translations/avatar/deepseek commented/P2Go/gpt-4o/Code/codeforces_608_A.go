package main

import (
	"fmt"
)

func main() {
	var n, s int
	fmt.Scan(&n, &s)

	// Initialize the maximum additional time to 0
	c := 0

	// Loop through each event
	for i := 0; i < n; i++ {
		var f, t int
		fmt.Scan(&f, &t)

		// Calculate the additional time required if the event starts at time s
		x := t - (s - f)

		// Update the maximum additional time if the current event requires more time
		if x > c {
			c = x
		}
	}

	// Print the total time including the maximum additional time
	fmt.Println(s + c)
}

// <END-OF-CODE>
