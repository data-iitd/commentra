package main

import (
	"fmt"
	"math"
)

func main() {
	// Reading the number of seconds from user input
	var sec int
	fmt.Scan(&sec)

	// Reading the number of items per interval from user input
	var perNum int
	fmt.Scan(&perNum)

	// Reading the maximum time limit, adding 0.5 to ensure proper rounding
	var maxSec float64
	fmt.Scan(&maxSec)
	maxSec += 0.5

	// Initializing a variable to hold the total count of items
	ansNum := 0

	// Looping from 'sec' to 'maxSec' in increments of 'sec'
	for i := sec; float64(i) < maxSec; i += sec {
		// Accumulating the total number of items produced
		ansNum += perNum
	}

	// Outputting the total number of items produced
	fmt.Println(ansNum)
}

// <END-OF-CODE>
