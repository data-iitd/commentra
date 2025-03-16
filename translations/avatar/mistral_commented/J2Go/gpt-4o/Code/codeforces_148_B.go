package main

import (
	"fmt"
)

func main() {
	var VP, VD, T, F, C float64

	// Read input values
	fmt.Scan(&VP, &VD, &T, &F, &C)

	if VD <= VP { // Check if VD is less than or equal to VP
		fmt.Println("0") // If it is, then the answer is 0
		return
	}

	answer := 0
	start := T

	for {
		x := start * VP / (VD - VP) // Calculate the time it takes to fill a volume VP

		if (start + x) * VP >= C { // Check if the total volume filled is greater than or equal to C
			break // If it is, then we break out of the loop
		}

		start += 2*x + F // Update the value of start
		answer++ // Increment the value of answer
	}

	fmt.Println(answer) // Print the value of answer
}

// <END-OF-CODE>
