package main // Step 1: Define the main package

import (
	"fmt" // Step 2: Import necessary packages
)

func main() { // Step 3: Define the main function
	var N, R int // Step 4: Declare variables

	fmt.Scanf("%d %d", &N, &R) // Step 5: Read input values

	if N >= 10 { // Step 6: Implement conditional logic
		fmt.Println(R) // If true, print the value of R
	} else {
		fmt.Println(R + 100*(10-N)) // Otherwise, calculate and print the adjusted value of R
	}
} // Step 7: End of main function

// <END-OF-CODE>
