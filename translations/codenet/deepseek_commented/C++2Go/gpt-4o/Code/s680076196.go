package main // Step 1: Define the main package

import ( // Step 1: Import necessary packages
	"fmt" // For input/output operations
)

func main() { // Step 3: Read input values
	var a, b, c, d int // Declare variables to store the input values
	fmt.Scan(&a, &b, &c, &d) // Read the four integer values from the user

	// Step 4: Perform calculations
	area := (a - c) * (b - d) // Calculate the area of the rectangle using the given coordinates

	// Step 5: Output the result
	fmt.Println(area) // Print the calculated area to the console
}

// <END-OF-CODE>
