package main

import (
	"fmt"
)

func main() {
	var train [2]int
	var bus [2]int

	fmt.Scan(&train[0], &train[1])
	fmt.Scan(&bus[0], &bus[1])

	fmt.Println(min(train[0], train[1]) + min(bus[0], bus[1]))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

