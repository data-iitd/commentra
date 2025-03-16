package main

import (
	"fmt"
)

func main() {
	var princess, dragon, t, f, c int
	fmt.Scan(&princess)  // Input the number of princess's power
	fmt.Scan(&dragon)    // Input the number of dragon's power
	fmt.Scan(&t)         // Input the initial time
	fmt.Scan(&f)         // Input the time increment
	fmt.Scan(&c)         // Input the target power level

	// Check if the dragon's power is less than or equal to the princess's power
	if dragon <= princess {
		fmt.Println(0) // If dragon is not stronger, no attacks needed
		return
	}

	result := 0 // Initialize the result counter
	position := t * princess // Calculate the initial position based on time and princess's power
	position += float64(princess * position) / float64(dragon - princess) // Adjust the position based on the given formula

	// Enter a while loop that continues until the position is greater than or equal to the target power level
	for position < float64(c) {
		result += 1 // Increment the result counter
		position += float64(princess * position) / float64(dragon) // Update the position based on the dragon's power
		position += float64(princess * f) // Add the time increment to the position
		position += float64(princess * position) / float64(dragon - princess) // Adjust the position based on the given formula
	}

	fmt.Println(result) // Print the number of attacks needed
}

