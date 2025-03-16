package main

import (
	"fmt"
)

func main() {
	var x int
	// Declare an integer variable 'x' to store the input value
	fmt.Scan(&x)
	// Read an integer value from the standard input and store it in 'x'
	if x >= 1200 {
		// Check if 'x' is greater than or equal to 1200
		fmt.Println("ARC")
		// If the condition is true, print "ARC" to the standard output
	} else {
		fmt.Println("ABC")
		// Otherwise, print "ABC" to the standard output
	}
}
