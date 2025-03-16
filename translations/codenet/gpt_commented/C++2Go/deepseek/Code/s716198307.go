package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	var a [100]float64 // Declare an integer n for the number of elements and an array a to store the elements
	var avg, s, ans float64 // Initialize variables for average, the smallest difference, and the index of the closest element

	// Input the number of elements
	fmt.Scan(&n)

	// Loop to read n elements into the array and calculate their sum
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read each element into the array
		avg += a[i] // Accumulate the sum of the elements
	}

	// Calculate the average of the elements
	avg /= float64(n)

	// Initialize the smallest difference with the absolute difference of the first element from the average
	s = math.Abs(a[0] - avg)
	ans = 0 // Initialize the index of the closest element to the first element

	// Loop to find the index of the element closest to the average
	for i := 1; i < n; i++ {
		// Check if the current element's difference from the average is smaller than the smallest found so far
		if s > math.Abs(a[i] - avg) {
			s = math.Abs(a[i] - avg) // Update the smallest difference
			ans = float64(i) // Update the index of the closest element
		}
	}

	// Output the index of the element closest to the average
	fmt.Println(int(ans))
}

