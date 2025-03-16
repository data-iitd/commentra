package main

import (
	"fmt"
)

func main() {
	// Declare two arrays to store the number of passengers in each train and bus
	train := [2]int{}
	bus := [2]int{}

	// Read the number of passengers in each train from the user
	fmt.Scan(&train[0], &train[1])

	// Comment: Read the number of passengers in the first and second train from the user

	// Read the number of passengers in each bus from the user
	fmt.Scan(&bus[0], &bus[1])

	// Comment: Read the number of passengers in the first and second bus from the user

	// Calculate the total number of passengers
	fmt.Println((train[0] < train[1] ? train[0] : train[1]) + (bus[0] < bus[1] ? bus[0] : bus[1]))

	// Comment: Output the total number of passengers in both train and bus
}

