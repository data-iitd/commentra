package main

import (
	"fmt"
)

func main() {
	// Declare arrays to hold the arrival times for train and bus
	train := [2]int{}
	bus := [2]int{}

	// Input the arrival times for the train
	fmt.Scan(&train[0], &train[1])
	// Input the arrival times for the bus
	fmt.Scan(&bus[0], &bus[1])

	// Calculate the minimum arrival time between the two times for train and bus,
	// and output the total minimum arrival time
	fmt.Println((train[0] < train[1] ? train[0] : train[1]) + (bus[0] < bus[1] ? bus[0] : bus[1]))
}

