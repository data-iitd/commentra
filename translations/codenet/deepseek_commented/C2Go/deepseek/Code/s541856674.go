package main

import (
	"fmt" // Step 1: Include necessary packages
)

func main() { // Step 2: Define the main function
	var N int // Step 3: Declare variables
	var R int

	fmt.Scan(&N, &R) // Step 4: Read input values

	if N >= 10 { // Step 5: Implement conditional logic
		fmt.Println(R) // If true, print the value of R
	} else {
		fmt.Println(R + 100*(10-N)) // Otherwise, calculate and print the adjusted value of R
	}
}

