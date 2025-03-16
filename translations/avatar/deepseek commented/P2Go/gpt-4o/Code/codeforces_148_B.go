package main

import (
	"fmt"
)

func main() {
	var princess, dragon, t, f, c int

	// Input the number of princess's power
	fmt.Scan(&princess)
	// Input the number of dragon's power
	fmt.Scan(&dragon)
	// Input the initial time
	fmt.Scan(&t)
	// Input the time increment
	fmt.Scan(&f)
	// Input the target power level
	fmt.Scan(&c)

	// Check if the dragon's power is less than or equal to the princess's power
	if dragon <= princess {
		fmt.Println(0) // If dragon is not stronger, no attacks needed
		return         // Exit the program
	}

	result := 0                     // Initialize the result counter
	position := t * princess         // Calculate the initial position based on time and princess's power
	position += princess * position / (dragon - princess) // Adjust the position based on the given formula

	// Enter a loop that continues until the position is greater than or equal to the target power level
	for position < c {
		result++ // Increment the result counter
		position += princess * position / dragon // Update the position based on the dragon's power
		position += princess * f // Add the time increment to the position
		position += princess * position / (dragon - princess) // Adjust the position based on the given formula
	}

	fmt.Println(result) // Print the number of attacks needed
}

// <END-OF-CODE>
