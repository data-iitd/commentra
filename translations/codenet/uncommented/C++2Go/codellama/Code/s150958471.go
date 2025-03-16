package main

import (
	"fmt"
)

func main() {
	var train [2]int
	var bus [2]int

	fmt.Scan(&train[0], &train[1])
	fmt.Scan(&bus[0], &bus[1])

	fmt.Println((train[0] < train[1] ? train[0] : train[1]) + (bus[0] < bus[1] ? bus[0] : bus[1]))
}

