package main // Step 1: Define the main package

import (
	"fmt" // Step 2: Import necessary packages
)

func main() { // Step 3: Define the main function
	var a, b, mawari, menseki int // Step 4: Declare variables

	fmt.Scanf("%d %d", &a, &b) // Step 5: Read input values
	mawari = 2 * (a + b) // Step 6: Calculate mawari
	menseki = a * b // Step 7: Calculate menseki
	fmt.Printf("%d %d\n", menseki, mawari) // Step 8: Print the results
} // Step 9: End of main function

// <END-OF-CODE>
