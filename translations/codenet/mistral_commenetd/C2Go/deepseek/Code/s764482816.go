package main

import (
	"fmt"
)

// Declare variables
var i, j, max, max_j, buf int
var io [5]int

// Read 5 integers from the user and store them in the array io
func readInput() {
	fmt.Scan(&io[0], &io[1], &io[2], &io[3], &io[4])
}

func main() {
	// Initialize variables
	readInput()

	// Perform bubble sort on the array io
	for i = 0; i < 5; i++ {
		// Initialize max and max_j with the first element of the array
		max = io[i]
		max_j = i

		// Compare the current element with the remaining elements
		for j = i + 1; j < 5; j++ {
			// If the current max is smaller than the next element, update max and max_j
			if max < io[j] {
				max = io[j]
				max_j = j
			}
		}

		// Swap the current element with the maximum element
		buf = io[i]
		io[i] = io[max_j]
		io[max_j] = buf

		// Print the sorted elements, except for the last one
		if i < 4 {
			fmt.Printf("%d ", io[i])
		} else {
			fmt.Printf("%d\n", io[i])
		}
	}

	// Return 0 to indicate successful execution
}

