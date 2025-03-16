package main

import (
	"fmt"
)

func main() {
	// Declare variables
	var n int // Number of elements in the array
	var sum int64 // Variable to store the total sum of differences

	// Read the number of elements from user input
	fmt.Scan(&n)
	
	// Declare an array of size n
	a := make([]int, n)

	// Read n elements into the array from user input
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Iterate through the array to calculate the sum of differences
	for i := 1; i < n; i++ {
		// Check if the previous element is greater than the current element
		if a[i - 1] > a[i] {
			// Calculate the difference and add it to the sum
			sum += int64(a[i - 1] - a[i])
			// Update the current element to be equal to the previous element
			a[i] = a[i - 1]
		}
	}

	// Print the total sum of differences
	fmt.Println(sum)
}

