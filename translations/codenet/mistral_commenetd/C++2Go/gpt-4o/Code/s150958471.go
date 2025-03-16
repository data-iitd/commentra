package main

import (
	"fmt"
)

func main() {
	// Declare two slices to store the number of passengers in each train and bus
	train := make([]int, 2)
	bus := make([]int, 2)

	// Read the number of passengers in each train from the user
	fmt.Scan(&train[0], &train[1])

	// Comment: Read the number of passengers in the first and second train from the user

	// Read the number of passengers in each bus from the user
	fmt.Scan(&bus[0], &bus[1])

	// Comment: Read the number of passengers in the first and second bus from the user

	// Calculate the total number of passengers
	totalPassengers := min(train[0], train[1]) + min(bus[0], bus[1])
	fmt.Println(totalPassengers)

	// Comment: Output the total number of passengers in both train and bus
}

// min function to return the smaller of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
