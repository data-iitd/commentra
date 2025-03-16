package main // Declaring the main package

import (
	"fmt" // Importing the fmt package for formatted I/O
)

func main() { // Starting the main function
	var a, b, c, d, e, f int // Declaring variables a to f as integers
	var x, y float64        // Declaring variables x and y as float64

	for { // Starting an infinite loop
		_, err := fmt.Scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f) // Reading input
		if err != nil { // Checking if there was an error in reading input
			break // Exiting the loop if there was an error
		}

		// Input is valid, so process it
		y = float64(c*d-f*a) / float64(b*d-e*a) // Calculating the value of y using the given formula
		x = float64(c*e-f*b) / float64(a*e-d*b) // Calculating the value of x using the given formula

		if y <= 0.0005 { // Checking if y is less than or equal to a very small positive number
			y = 0 // If so, set y to 0
		}
		if x <= 0.0005 { // Checking if x is less than or equal to a very small positive number
			x = 0 // If so, set x to 0
		}
		fmt.Printf("%.3f %.3f\n", x, y) // Printing the values of x and y to the standard output with three decimal places
	}
}
