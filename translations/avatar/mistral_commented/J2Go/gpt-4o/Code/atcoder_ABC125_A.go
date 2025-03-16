package main

import (
	"fmt"
)

func main() {
	// Create a variable to read input from the standard input stream
	var sec, perNum, maxSec int

	// Read three integers from the standard input: the number of seconds, the number of periods, and the total number of seconds
	fmt.Scan(&sec)    // Read the number of seconds
	fmt.Scan(&perNum) // Read the number of periods
	fmt.Scan(&maxSec) // Read the total number of seconds

	// Convert the last input (maxSec) to a float64 type and add 0.5 to it to get the maximum number of seconds with a fractional part
	maxSecFloat := float64(maxSec) + 0.5 // Convert to float64 and add 0.5

	// Initialize a counter variable ansNum to zero
	ansNum := 0

	// Start a for loop that runs from the initial value sec to the final value maxSecFloat with a step size of sec. In each iteration of the loop, add perNum to ansNum
	for i := sec; float64(i) < maxSecFloat; i += sec {
		ansNum += perNum
	}

	// Print the result ansNum to the standard output stream
	fmt.Println(ansNum)
}
