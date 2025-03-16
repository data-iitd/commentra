package main

import (
	"fmt" // Import the format package for printing
)

func main() {
	var a, b, h int // Declare three integer variables: a, b, and h

	fmt.Print("Enter the values of a, b, and h: ") // Print a message asking for user input
	fmt.Scan(&a, &b, &h) // Read three integers from the user and store them in variables a, b, and h

	// Calculate the area of the rectangle using the formula: area = length * width
	fmt.Println((a + b) * h / 2) // Print the result, which is the area of the rectangle
}

