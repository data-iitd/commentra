package main

import (
	"fmt"
)

func main() {
	// Initialize variables
	var N, D, X int // Number of days, maximum days, and extra chocolate
	var num_of_chocolate int // Total number of chocolate pieces

	// Read input
	fmt.Scan(&N, &D, &X)

	// Initialize slice A to store the number of chocolate pieces for each day
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Read the number of chocolate pieces for the i-th day
	}

	// Calculate the total number of chocolate pieces
	num_of_chocolate = 0
	for i := 0; i < N; i++ {
		// Initialize variables for inner loop
		days := 0
		counter := 0

		// Calculate the number of days this chocolate piece lasts
		for j := 0; ; j++ {
			days = j*A[i] + 1 // Calculate the number of days
			if days <= D { // Check if the number of days is less than or equal to the maximum number of days
				counter++ // Increment the counter
			} else { // If the number of days is greater than the maximum number of days, break the loop
				break
			}
		}

		// Add the number of chocolate pieces eaten in this day to the total number of chocolate pieces
		num_of_chocolate += counter
	}

	// Add the extra chocolate
	num_of_chocolate += X

	// Output the result
	fmt.Println(num_of_chocolate)
}

// <END-OF-CODE>
