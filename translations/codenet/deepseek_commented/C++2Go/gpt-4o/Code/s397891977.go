package main // Step 1: Define the main package

import (
	"fmt" // Import the fmt package for input/output operations
)

func main() { // Step 2: Define the main function
	var r int // Step 3: Declare an integer variable to store the input
	fmt.Scan(&r) // Read an integer input from the user

	fmt.Println(r * r) // Step 4: Calculate the square of the input and output the result
}

// <END-OF-CODE>
