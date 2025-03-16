package main

import (
	"fmt"
)

func main() {
	var VP, VD, T, F, C float64 // Declare variables for speeds, time, and distance

	fmt.Scan(&VP) // Read the initial speed of the police car (VP)
	fmt.Scan(&VD) // Read the initial speed of the thief car (VD)
	fmt.Scan(&T)  // Read the initial head start time (T)
	fmt.Scan(&F)  // Read the time it takes for the police car to refuel (F)
	fmt.Scan(&C)  // Read the distance to catch the thief (C)

	if VD <= VP {
		fmt.Println(0) // If the thief's speed is not greater than the police's speed, print 0 and exit
		return
	}

	answer := 0    // Initialize the answer variable to 0
	start := T     // Initialize the start variable to the initial head start time (T)

	for {
		x := start * VP / (VD - VP) // Calculate the distance covered by the police car in one unit of time

		if (start + x)*VP >= C { // If the total distance covered by the police car is greater than or equal to C, break the loop
			break
		}

		start += 2*x + F // Update the start variable by adding the distance covered and the refueling time
		answer++         // Increment the answer variable by 1
	}

	fmt.Println(answer) // Print the final value of answer
}

// <END-OF-CODE>
