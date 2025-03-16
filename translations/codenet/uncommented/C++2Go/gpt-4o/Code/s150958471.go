package main

import (
	"fmt"
)

func main() {
	var train [2]int
	var bus [2]int

	fmt.Scan(&train[0], &train[1])
	fmt.Scan(&bus[0], &bus[1])

	minTrain := train[0]
	if train[1] < minTrain {
		minTrain = train[1]
	}

	minBus := bus[0]
	if bus[1] < minBus {
		minBus = bus[1]
	}

	fmt.Println(minTrain + minBus)
}

// <END-OF-CODE>
