
package main

import "fmt"

// Function to calculate the greatest common divisor (GCD) of two numbers
func you(x, y int) int {
	var z int // Declare a variable z to store the remainder

	// Repeat the following steps until y becomes zero
	for y!= 0 {
		// Calculate the remainder of x divided by y and store it in z
		z = x % y

		// Update the values of x and y
		x = y
		y = z
	}

	// Return the final value of x, which is the greatest common divisor
	return x
}

func main() {
	// Declare variables x, y, and z
	var x, y, z int

	// Read two integers from the user using fmt.Scan
	fmt.Print("Enter two integers: ")
	fmt.Scan(&x, &y)

	// Determine which number is greater and call the you() function with the appropriate arguments
	if x >= y {
		z = you(x, y) // Call the you() function with x and y as arguments
	} else {
		z = you(y, x) // Call the you() function with y and x as arguments
	}

	// Print the result (the greatest common divisor) to the console
	fmt.Printf("The greatest common divisor of %d and %d is: %d\n", x, y, z)
}

// 