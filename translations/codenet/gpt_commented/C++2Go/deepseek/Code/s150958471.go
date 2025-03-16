package main

import (
	"fmt"
)

func main() {
	// Declare arrays to hold the arrival times for train and bus
	var train [2]int
	var bus [2]int

	// Input the arrival times for the train
	fmt.Scan(&train[0], &train[1])
	// Input the arrival times for the bus
	fmt.Scan(&bus[0], &bus[1])

	// Calculate the minimum arrival time between the two times for train and bus,
	// and output the total minimum arrival time
	minTrain := train[0]
	if train[0] > train[1] {
		minTrain = train[1]
	}

	minBus := bus[0]
	if bus[0] > bus[1] {
		minBus = bus[1]
	}

	fmt.Println(minTrain + minBus)
}

