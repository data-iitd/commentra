package main

import (
	"fmt"
)

func main() {
	// Declare two arrays to store the number of passengers in each train and bus
	var train [2]int
	var bus [2]int

	// Read the number of passengers in each train from the user
	fmt.Scan(&train[0], &train[1])

	// Read the number of passengers in each bus from the user
	fmt.Scan(&bus[0], &bus[1])

	// Calculate the total number of passengers
	totalPassengers := (train[0] < train[1] ? train[0] : train[1]) + (bus[0] < bus[1] ? bus[0] : bus[1])

	// Output the total number of passengers in both train and bus
	fmt.Println(totalPassengers)
}

