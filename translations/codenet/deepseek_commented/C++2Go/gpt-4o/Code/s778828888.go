package main

import (
	"fmt"
)

func main() {
	var n, m, x int
	a := make([]int, 106) // Step 2: Initialize slice to keep track of positions

	fmt.Scanf("%d %d %d", &n, &m, &x) // Step 1: Read the values of n, m, and x

	for i := 0; i < m; i++ {
		var temp int
		fmt.Scanf("%d", &temp) // Read the positions to be marked
		a[temp] = 1 // Step 3: Mark the positions in slice a
	}

	ansl, ansr := 0, 0 // Initialize variables to store distances
	for i := x; i <= n; i++ { // Step 4: Calculate the number of marked positions to the right of x
		ansr += a[i]
	}
	for i := x; i >= 0; i-- { // Calculate the number of marked positions to the left of x
		ansl += a[i]
	}

	fmt.Println(min(ansl, ansr)) // Step 5: Print the minimum of the left and right distances
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
