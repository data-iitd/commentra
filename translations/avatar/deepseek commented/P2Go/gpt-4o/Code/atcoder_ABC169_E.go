package main

import (
	"fmt"
	"sort"
)

func resolve() {
	// Read the number of pairs
	var n int
	fmt.Scan(&n)

	// Initialize slices to store the lower and higher values of each pair
	low := make([]int, n)
	high := make([]int, n)

	// Loop to read each pair and append values to the slices
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		low[i] = a
		high[i] = b
	}

	// Sort the slices
	sort.Ints(low)
	sort.Ints(high)

	// Check if the number of pairs is odd or even
	if n%2 == 1 {
		// If odd, calculate the range between the middle elements
		mid := (n + 1) / 2 - 1
		fmt.Println(high[mid] - low[mid] + 1)
	} else {
		// If even, calculate the average of the middle elements and print the range
		hh := float64(high[n/2-1]+high[n/2]) / 2
		ll := float64(low[n/2-1]+low[n/2]) / 2
		fmt.Println(int((hh-ll)*2) + 1)
	}
}

// Call the resolve function when the script is executed
func main() {
	resolve()
}

// <END-OF-CODE>
