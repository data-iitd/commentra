package main

import (
	"fmt"
)

func main() {
	// Declare variables to store input value and average
	var a float64
	var ave float64 = 0
	var i int

	// Loop to read 5 input values
	for i = 0; i < 5; i++ {
		// Read a double value from user input
		fmt.Scanf("%f", &a)

		// Check if the input value is less than or equal to 40
		if a <= 40 {
			// If so, add 40 to the average instead of the input value
			ave += 40
		} else {
			// Otherwise, add the input value to the average
			ave += a
		}
	}

	// Calculate the average by dividing the total by the number of inputs (5)
	ave /= 5.0

	// Print the calculated average, formatted as an integer
	fmt.Printf("%.0f\n", ave)

	// Return 0 to indicate successful completion of the program
	return
}

