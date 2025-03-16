package main // Step 1: Define the main package

import (
	"fmt" // Step 2: Import necessary libraries
)

func main() {
	var a, b int
	fmt.Scan(&a, &b) // Step 4: Read input values
	if a <= 8 && b <= 8 {
		fmt.Println("Yay!") // Step 5: Check the condition and print the result
	}
} // Step 7: End the main function
// <END-OF-CODE>
