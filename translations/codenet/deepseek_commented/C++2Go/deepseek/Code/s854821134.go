package main

import (
	"fmt" // Step 1: Include necessary libraries
)

const INF = 200000005 // Step 2: Define constants

func main() {
	var a, b int // Step 3: Declare variables
	fmt.Scan(&a, &b) // Step 4: Read input values
	if a <= 8 && b <= 8 { // Step 5: Check the condition and print the result
		fmt.Println("Yay!")
	}
	// Step 7: End the main function
}

