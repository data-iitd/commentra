package main

import (
	"fmt"
	"math"
)

func ABS(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	var N int // Variable to store the number of test cases
	var t, x, y, nx, ny, nt int // Variables to store the current test case data and previous coordinates

	// Read the number of test cases
	fmt.Scan(&N)

	// Loop through each test case
	for i := 0; i < N; i++ {
		// Read the current test case data (t, x, y)
		fmt.Scan(&t, &x, &y)

		// Calculate the temporary variable 'tmp' to check the distance between the current and previous coordinates
		tmp := t - nt - (ABS(x-nx) + ABS(y-ny))

		// Check if the current test case satisfies the condition
		if tmp < 0 || tmp%2 != 0 {
			// If the condition is not satisfied, print 'No' and exit the program
			fmt.Println("No")
			return
		}

		// Update the previous coordinates for the next iteration
		nx = x
		ny = y
		nt = t
	}

	// If all the test cases satisfy the condition, print 'Yes'
	fmt.Println("Yes")
}

// <END-OF-CODE>
