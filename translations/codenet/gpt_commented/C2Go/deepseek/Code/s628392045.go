package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n, i int
	var h [100001]int
	var max int = -1
	var flag bool = false

	// Read the number of elements
	fmt.Scan(&n)

	// Loop to read heights and determine the maximum height
	for i = 0; i < n; i++ {
		// Read height into the array
		fmt.Scan(&h[i])
		
		// Update maximum height if current height is greater
		if max < h[i] {
			max = h[i]
		}

		// Check if the difference between max height and current height is 2 or more
		if max - h[i] >= 2 {
			flag = true // Set flag if condition is met
		}
	}

	// Output result based on the flag value
	if flag {
		fmt.Println("No") // If flag is set, print "No"
	} else {
		fmt.Println("Yes") // If flag is not set, print "Yes"
	}
}

