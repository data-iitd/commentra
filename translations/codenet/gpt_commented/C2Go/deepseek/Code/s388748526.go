package main

import (
	"fmt"  // Import the fmt package for formatted I/O operations
	"math" // Import the math package for mathematical constants and functions
)

func main() {
	var r float64  // Declare a variable to store the radius

	// Prompt the user to input the radius
	fmt.Print("Enter the radius: ")
	fmt.Scan(&r)  // Read the radius from user input

	// Calculate and print the area and circumference of the circle
	// Area = π * r^2
	// Circumference = 2 * π * r
	fmt.Printf("%f %f\n", r * r * math.Pi, 2 * math.Pi * r)
}

