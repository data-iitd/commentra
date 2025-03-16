package main

import (
	"fmt"
)

func main() {
	var n int // Variable to store the number of elements
	fmt.Scan(&n) // Read the number of elements from input

	p := make([]int, n) // Declare a slice to hold the elements
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i]) // Read the elements into the slice
	}

	ans := 0 // Initialize a counter for the number of valid triplets
	// Loop through the slice to check for increasing or decreasing triplets
	for i := 0; i < n-2; i++ {
		// Check if the current triplet is strictly decreasing
		if p[i] > p[i+1] && p[i+1] > p[i+2] {
			ans++ // Increment the counter for decreasing triplet
		}

		// Check if the current triplet is strictly increasing
		if p[i] < p[i+1] && p[i+1] < p[i+2] {
			ans++ // Increment the counter for increasing triplet
		}
	}

	fmt.Println(ans) // Output the total count of valid triplets
}

// <END-OF-CODE>
