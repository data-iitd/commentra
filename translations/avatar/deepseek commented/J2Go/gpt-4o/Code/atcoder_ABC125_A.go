package main

import (
	"fmt"
)

func main() {
	var sec, perNum int
	var maxSec float64

	// Reading inputs
	fmt.Scan(&sec)
	fmt.Scan(&perNum)
	fmt.Scan(&maxSec)

	maxSec += 0.5 // Adding 0.5 to maxSec

	ansNum := 0 // Initializing the variable to store the result of additions.

	// Loop to iterate from 'sec' to 'maxSec' in steps of 'sec' and add 'perNum' to 'ansNum' each time.
	for i := sec; float64(i) < maxSec; i += sec {
		ansNum += perNum
	}

	fmt.Println(ansNum) // Printing the final result after the loop completes.
}

// <END-OF-CODE>
