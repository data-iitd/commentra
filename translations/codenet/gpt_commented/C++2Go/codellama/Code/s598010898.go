package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n int
	a := make([]int, 100)
	b := make([]int, 100)
	sum := 0

	// Read the number of elements
	fmt.Scan(&n)

	// Input the first array 'a'
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Input the second array 'b' and calculate the sum of positive differences
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i]) // Read each element of array 'b'

		// Check if the difference between corresponding elements of 'a' and 'b' is positive
		if a[i]-b[i] > 0 {
			// If positive, add the difference to 'sum'
			sum += a[i] - b[i]
		}
	}

	// Output the final sum of positive differences
	fmt.Println(sum)
}

