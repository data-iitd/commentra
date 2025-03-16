package main

import (
	"fmt"
	"math"
)

func main() {
	var n int // Declare an integer n for the number of elements
	var a [100]int // Declare an array a to store the elements
	var avg float64 = 0 // Initialize a variable for the average
	var s float64 = 0 // Initialize a variable for the smallest difference
	var ans int = 0 // Initialize a variable for the index of the closest element

	// Input the number of elements
	fmt.Scan(&n)

	// Loop to read n elements into the array and calculate their sum
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i]) // Read each element into the array
		avg += float64(a[i]) // Accumulate the sum of the elements
	}

	// Calculate the average of the elements
	avg /= float64(n)

	// Initialize the smallest difference with the absolute difference of the first element from the average
	s = math.Abs(float64(a[0]) - avg)
	ans = 0 // Initialize the index of the closest element to the first element

	// Loop to find the index of the element closest to the average
	for i := 1; i < n; i++ {
		// Check if the current element's difference from the average is smaller than the smallest found so far
		if s > math.Abs(float64(a[i])-avg) {
			s = math.Abs(float64(a[i]) - avg) // Update the smallest difference
			ans = i // Update the index of the closest element
		}
	}

	// Output the index of the element closest to the average
	fmt.Println(ans)
}

