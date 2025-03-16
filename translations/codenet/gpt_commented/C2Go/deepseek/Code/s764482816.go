package main

import (
	"fmt"
)

func main() {
	// Declare variables for iteration, maximum value, index of maximum value, and a buffer for swapping
	var i, j, max, maxJ, buf int
	// Array to hold 5 integer inputs
	var io [5]int

	// Read 5 integers from user input
	fmt.Scan(&io[0], &io[1], &io[2], &io[3], &io[4])

	// Outer loop to iterate through each element in the array
	for i = 0; i < 5; i++ {
		// Assume the current element is the maximum
		max = io[i]
		maxJ = i // Store the index of the maximum element

		// Inner loop to find the maximum element in the remaining unsorted portion of the array
		for j = i + 1; j < 5; j++ {
			// If a larger element is found, update max and maxJ
			if max < io[j] {
				max = io[j]
				maxJ = j
			}
		}

		// Swap the found maximum element with the current element
		buf = io[i]
		io[i] = io[maxJ]
		io[maxJ] = buf

		// Print the current element, ensuring proper formatting for the last element
		if i < 4 {
			fmt.Printf("%d ", io[i])
		} else {
			fmt.Printf("%d\n", io[i])
		}
	}
}

