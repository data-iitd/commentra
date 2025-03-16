package main

import (
	"fmt"
	"math"
)

func main() {
	// Declare variables
	var n int // Number of elements in the array
	var avg float64 // Average of the elements in the array
	var s float64 // Difference between the first element and the average
	var ans int // Index of the element with the maximum difference from the average

	// Initialize variables
	fmt.Scan(&n) // Read the number of elements from the standard input
	a := make([]int, 100) // Declare and initialize an array of size 100 with zeros

	// Calculate the average of the elements in the array
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read an element from the standard input and store it in the array
		avg += float64(a[i]) // Add the current element to the sum of all elements
	}

	// Calculate the average and divide it by the number of elements
	avg /= float64(n)

	// Initialize the difference between the first element and the average
	s = math.Abs(float64(a[0]) - avg)

	// Initialize the index of the element with the maximum difference from the average
	ans = 0

	// Find the index of the element with the maximum difference from the average
	for i := 1; i < n; i++ {
		if s > math.Abs(float64(a[i]) - avg) { // If the current difference is greater than the previous difference
			s = math.Abs(float64(a[i]) - avg) // Update the difference
			ans = i // Update the index
		}
	}

	// Print the index of the element with the maximum difference from the average
	fmt.Println(ans)

	// Terminate the program
	return
}

