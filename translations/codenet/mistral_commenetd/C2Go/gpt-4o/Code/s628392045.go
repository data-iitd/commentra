package main

import (
	"fmt"
)

func main() {
	// Declare and initialize variables
	var n, max int
	var flag int
	h := make([]int, 100001)

	// Read the number of test cases
	fmt.Scan(&n)

	// Read and process input
	for i := 0; i < n; i++ {
		// Read the next integer from standard input and store it in the array h
		fmt.Scan(&h[i])

		// Update the maximum height if the current height is greater
		if max < h[i] {
			max = h[i]
		}

		// Check if the difference between the current height and maximum height is greater than or equal to 2
		if max-h[i] >= 2 {
			flag = 1
		}
	}

	// Check the value of the flag and print the appropriate message to the standard output
	if flag == 1 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

// <END-OF-CODE>
