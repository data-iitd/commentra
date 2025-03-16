package main

import (
	"fmt"
	"os"
)

func main() {
	// Declare three integer variables to store user input
	var a, b, c int

	// Read three integers from the standard input
	fmt.Scan(&a, &b, &c)

	// Check if the sum of a and b is greater than or equal to c
	if a+b >= c {
		// If true, print "Yes"
		fmt.Println("Yes")
	} else {
		// Otherwise, print "No"
		fmt.Println("No")
	}

	// Return 0 to indicate successful execution
	os.Exit(0)
}

