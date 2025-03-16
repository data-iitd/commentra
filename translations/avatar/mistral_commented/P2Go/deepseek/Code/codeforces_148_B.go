package main

import (
	"fmt"
)

func main() {
	// Read in five integers from the standard input
	var princess, dragon, t, f, c int
	fmt.Scan(&princess, &dragon, &t, &f, &c)

	// Check if the dragon is smaller than or equal to the princess
	// If so, print 0 and exit the program
	if dragon <= princess {
		fmt.Println(0)
		return
	}

	// Initialize a variable result to 0
	result := 0

	// Calculate an initial position based on t and princess
	position := t * princess

	// Enter a while loop that continues as long as the position is less than c
	for position < c {
		// Increment result by 1
		result++

		// Update the position by adding the given terms
		position += float64(princess) * float64(position) / float64(dragon)
		position += float64(princess) * float64(f)
		position += float64(princess) * float64(position) / float64(dragon - princess)
	}

	// Once the loop terminates, print the final value of result
	fmt.Println(result)
}
