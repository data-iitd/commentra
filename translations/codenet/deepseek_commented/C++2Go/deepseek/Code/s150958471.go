package main

import (
	"fmt"
)

func main() {
	// Declare arrays
	var train [2]int
	var bus [2]int

	// Input values
	fmt.Scan(&train[0], &train[1])
	fmt.Scan(&bus[0], &bus[1])

	// Calculate the sum
	minTrain := train[0]
	if train[1] < minTrain {
		minTrain = train[1]
	}

	minBus := bus[0]
	if bus[1] < minBus {
		minBus = bus[1]
	}

	sum := minTrain + minBus

	// Output the result
	fmt.Println(sum)
}
