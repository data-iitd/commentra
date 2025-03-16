package main

import (
	"fmt"
	"sort"
)

func resolve() {
	// Read the number of intervals
	var n int
	fmt.Scan(&n)

	// Initialize slices to store the lower and upper bounds of the intervals
	low := make([]int, n)
	high := make([]int, n)

	// Read each interval and store the lower and upper bounds
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		low[i] = a  // Append the lower bound to the low slice
		high[i] = b // Append the upper bound to the high slice
	}

	// Sort the lower and upper bounds
	sort.Ints(low)
	sort.Ints(high)

	// Check if the number of intervals is odd
	if n%2 == 1 {
		// For odd number of intervals, calculate the range of the median interval
		fmt.Println(high[(n+1)/2-1] - low[(n+1)/2-1] + 1)
	} else {
		// For even number of intervals, calculate the average of the two middle values
		hh := float64(high[n/2-1]+high[n/2]) / 2.0 // Average of the two middle high values
		ll := float64(low[n/2-1]+low[n/2]) / 2.0   // Average of the two middle low values
		// Calculate the range and print the result
		fmt.Println(int((hh-ll)*2) + 1)
	}
}

// Entry point of the program
func main() {
	resolve()
}

// <END-OF-CODE>
