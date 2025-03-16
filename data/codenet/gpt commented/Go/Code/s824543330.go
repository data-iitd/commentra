package main

import "fmt"

func main() {
	// Declare two integer variables to hold the input values
	var a, b int
	
	// Read two integers from standard input
	fmt.Scan(&a, &b)

	// Check if the product of a and b is even or odd
	if a*b%2 == 0 {
		// If the product is even, print "Even"
		fmt.Println("Even")
	} else {
		// If the product is odd, print "Odd"
		fmt.Println("Odd")
	}
}
