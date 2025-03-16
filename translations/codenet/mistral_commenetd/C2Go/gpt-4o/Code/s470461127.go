package main

import (
	"fmt"
)

func main() {
	// Declare two integer variables x and y
	var x, y int

	// Read two integers from the user using fmt.Scan and store them in variables x and y respectively
	fmt.Scan(&x, &y)

	// Print the product of x and y and the sum of 2 times x and 2 times y
	fmt.Printf("%d %d\n", x*y, (2*x)+(2*y))

	// Return 0 to indicate successful execution of the program
}

// <END-OF-CODE>
