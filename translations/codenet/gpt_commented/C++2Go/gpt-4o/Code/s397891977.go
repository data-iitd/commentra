package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() {
	var r int // Declare an integer variable 'r' to store the radius

	// Read the radius value from user input
	fmt.Scan(&r)

	// Calculate the area of the circle using the formula πr²
	// Here, we are using the simplified version by omitting π for demonstration
	fmt.Println(r * r) // Output the calculated area (r squared)
}

// <END-OF-CODE>
