package main

import (
	"fmt"
)

// Declare variables
var i, j, max, maxJ, buf int
var io [5]int

// Read 5 integers from the user and store them in the array io
func readInput() {
	for k := 0; k < 5; k++ {
		fmt.Scan(&io[k])
	}

}

func main() {
	// Initialize variables
	readInput()

	// Perform bubble sort on the array io
	for i = 0; i < 5; i++ {
		// Initialize max and maxJ with the first element of the array
		max = io[i]
		maxJ = i

		// Compare the current element with the remaining elements
		for j = i + 1; j < 5; j++ {
			// If the current max is smaller than the next element, update max and maxJ
			if max < io[j] {
				max = io[j]
				maxJ = j
			}
		}

		// Swap the current element with the maximum element
		buf = io[i]
		io[i] = io[maxJ]
		io[maxJ] = buf

		// Print the sorted elements, except for the last one
		if i < 4 {
			fmt.Printf("%d ", io[i])
		} else {
			fmt.Printf("%d\n", io[i])
		}
	}
}

// <END-OF-CODE>
