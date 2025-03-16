package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare two integer variables to hold user input
	var a, b int

	// Read the first integer from user input
	fmt.Scanf("%d", &a)

	// Read the second integer from user input
	fmt.Scanf("%d", &b)

	// Check if the product of a and b is even
	if (a * b) % 2 == 0 {
		// If the product is even, print "Even"
		fmt.Println("Even")
	} else {
		// If the product is odd, print "Odd"
		fmt.Println("Odd")
	}

	// Return 0 to indicate successful completion of the program
	os.Exit(0)
}

