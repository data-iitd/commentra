package main

import (
	"fmt"
)

func main() {
	var x, y int

	// Read two integers from the standard input and store them in x and y
	fmt.Scan(&x, &y)

	// Calculate the product of x and y
	// Also, calculate the perimeter of a rectangle with sides x and y
	fmt.Printf("%d %d\n", x*y, (2*x)+(2*y))
}

// <END-OF-CODE>
