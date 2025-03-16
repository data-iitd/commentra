package main

import (
	"fmt"
	"math"
)

func main() {
	// Declare variables
	var n int
	var avg, s float64
	var ans int

	// Initialize variables
	fmt.Scan(&n) // Read the number of elements from the standard input
	a := make([]float64, n) // Declare and initialize an array of size n

	// Calculate the average of the elements in the array
	var sum float64
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read an element from the standard input and store it in the array
		sum += a[i]     // Add the current element to the sum of all elements
	}

	// Calculate the average and divide it by the number of elements
	avg = sum / float64(n)

	// Initialize the difference between the first element and the average
	s = math.Abs(a[0] - avg)

	// Initialize the index of the element with the maximum difference from the average
	ans = 0

	// Find the index of the element with the maximum difference from the average
	for i := 1; i < n; i++ {
		if s > math.Abs(a[i] - avg) { // If the current difference is greater than the previous difference
			s = math.Abs(a[i] - avg) // Update the difference
			ans = i                  // Update the index
		}
	}

	// Print the index of the element with the maximum difference from the average
	fmt.Println(ans)
}

