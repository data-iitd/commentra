package main

import (
	"fmt"
)

func main() {
	var VP, VD, T, F, C float64

	// Reading input values for VP, VD, T, F, and C
	fmt.Scan(&VP) // Velocity of the person
	fmt.Scan(&VD) // Velocity of the dog
	fmt.Scan(&T)  // Initial time before the dog starts chasing
	fmt.Scan(&F)  // Time taken for the dog to return to the person
	fmt.Scan(&C)  // Distance the person needs to cover

	// If the dog's velocity is less than or equal to the person's velocity, the dog cannot catch up
	if VD <= VP {
		fmt.Println("0") // Output 0 as the dog will never catch the person
		return           // Exit the program
	}

	answer := 0      // Initialize the number of times the dog catches up
	start := T       // Start time for the first chase

	// Loop to calculate how many times the dog can catch the person
	for {
		// Calculate the distance the person covers before the dog catches up
		x := start * VP / (VD - VP)

		// Check if the distance covered by the person is greater than or equal to C
		if (start + x)*VP >= C {
			break // Exit the loop if the person has covered the required distance
		}

		// Update the start time for the next chase
		start += 2*x + F // Add the time taken for the dog to return and the time to catch up
		answer++          // Increment the count of catches
	}

	// Output the total number of times the dog catches the person
	fmt.Println(answer)
}

// <END-OF-CODE>
