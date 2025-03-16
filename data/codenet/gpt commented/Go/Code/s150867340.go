package main

import "fmt"

func main() {
	// Declare two integer variables to hold the input values
	var a, b int
	
	// Read two integers from standard input
	fmt.Scan(&a, &b)
	
	// Calculate the product of the two integers and check if it is even or odd
	if product := a * b; product%2 == 0 {
		// If the product is even, print "Even"
		fmt.Println("Even")
	} else {
		// If the product is odd, print "Odd"
		fmt.Println("Odd")
	}
}
