package main

import "fmt"

func main() {
	// Declare and initialize variables
	i := 1 // Initialize counter variable i to 1
	var Input int // Declare variable to store user input

	for {
		// Read user input and store it in the Input variable
		fmt.Scan(&Input)

		// Check if user input is 0
		if Input == 0 {
			// If user input is 0, break out of the loop
			break
		}

		// Print the case number and user input
		fmt.Printf("Case %d: %d\n", i, Input)

		// Increment the counter variable i
		i++
	}

	// Return 0 to indicate successful execution of the program
	return
}

