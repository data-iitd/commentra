package main

import (
	"fmt" // Step 1: Include the standard input/output library.
)

func main() { // Step 2: Define the main function.
	var a, b, h int // Step 3: Declare three integer variables a, b, and h.
	
	// Step 4: Read three integer values from the user and store them in a, b, and h.
	fmt.Scan(&a, &b, &h) 
	
	// Step 5: Calculate the area of a trapezoid using the formula (a+b)*h/2.
	fmt.Println((a+b)*h/2) 
	
	// Step 7: End the main function and return 0.
}
