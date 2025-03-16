package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int // Declare variables for number of elements and loop index
	var i int
	var h [100001]int // Declare an array to store heights of elements
	var max int = -1 // Initialize max to -1 to store the maximum height found
	var flag int = 0 // Initialize flag to 0 to indicate whether the condition is met

	fmt.Scan(&n) // Read the number of elements from the standard input

	// Loop to read heights and update the maximum height found
	for i = 0; i < n; i++ {
		fmt.Scan(&h[i]) // Read the height of the i-th element
		if max < h[i] {
			max = h[i] // Update max if the current height is greater than max
		}

		if max-h[i] >= 2 {
			flag = 1 // Check if the difference between max and current height is at least 2
		}
	}

	if flag == 1 {
		fmt.Println("No") // Print "No" if the condition is met
	} else {
		fmt.Println("Yes") // Print "Yes" if the condition is not met
	}
}

