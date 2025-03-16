package main

import (
	"fmt"
)

func main() {
	// Initialize variables
	var N, D, X int
	var numOfChocolate int
	var counter int
	var days int

	// Read input
	fmt.Scan(&N, &D, &X)

	// Initialize array A to store the number of chocolate pieces for each day
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Read the number of chocolate pieces for the i-th day
	}

	// Calculate the total number of chocolate pieces
	numOfChocolate = 0
	for i := 0; i < N; i++ {
		// Initialize variables for inner loop
		days = 0
		counter = 0

		// Calculate the number of days this chocolate piece lasts
		for {
			days = counter*A[i] + 1 // Calculate the number of days
			if days <= D { // Check if the number of days is less than or equal to the maximum number of days
				counter++ // Increment the counter
			} else { // If the number of days is greater than the maximum number of days, break the loop
				break
			}
		}

		// Add the number of chocolate pieces eaten in this day to the total number of chocolate pieces
		numOfChocolate += counter
	}

	// Add the extra chocolate
	numOfChocolate += X

	// Output the result
	fmt.Println(numOfChocolate)
}

