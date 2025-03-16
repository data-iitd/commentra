package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n int // n: number of elements
	var max int = -1 // Variable to track the maximum height
	var flag int = 0 // Flag to indicate if the condition is met

	// Read the number of elements
	fmt.Scan(&n)

	// Loop to read heights and determine the maximum height
	h := make([]int, n) // Slice to store heights
	for i := 0; i < n; i++ {
		// Read height into the slice
		fmt.Scan(&h[i])

		// Update maximum height if current height is greater
		if max < h[i] {
			max = h[i]
		}

		// Check if the difference between max height and current height is 2 or more
		if max-h[i] >= 2 {
			flag = 1 // Set flag if condition is met
		}
	}

	// Output result based on the flag value
	if flag == 1 {
		fmt.Println("No") // If flag is set, print "No"
	} else {
		fmt.Println("Yes") // If flag is not set, print "Yes"
	}
}

// <END-OF-CODE>
