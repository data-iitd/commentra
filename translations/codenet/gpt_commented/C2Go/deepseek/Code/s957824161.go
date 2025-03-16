package main

import (
	"fmt"
)

// Declare global variables for storing two integers
var x, y int

func main() {
	// Read two integers from user input
	fmt.Scan(&x, &y)
	
	// Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
	// Print the results: product and perimeter
	fmt.Println(x * y, 2 * x + 2 * y)
	
	// Return 0 to indicate successful completion of the program
}

