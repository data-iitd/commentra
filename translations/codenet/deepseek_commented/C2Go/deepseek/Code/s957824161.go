package main

import (
	"fmt" // Import the fmt package for formatted I/O operations
)

var x, y int // Declare two integer variables to store user input

func main() { // Define the main function, the entry point of the program
	fmt.Scan(&x, &y) // Read two integers from the standard input and store them in x and y
	fmt.Println(x * y, 2*x+2*y) // Print the product of x and y and the perimeter of the rectangle
}

