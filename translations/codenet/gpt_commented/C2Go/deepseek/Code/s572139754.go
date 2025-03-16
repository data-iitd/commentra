package main

import (
	"fmt"
)

func main() {
	// Declare an integer variable to hold the input value
	var n int

	// Read an integer value from standard input
	fmt.Scan(&n)

	// Check if n is a multiple of 1000
	if n % 1000 == 0 {
		// If true, print 0 since no additional amount is needed to reach the next multiple of 1000
		fmt.Println(0)
	} else {
		// If false, calculate and print the difference to the next multiple of 1000
		fmt.Println((n / 1000 + 1) * 1000 - n)
	}
}

