package main

import (
	"fmt"
)

func main() {
	// Declare four integer variables to store input values
	var a, b, c, d int

	// Read input values from the user using fmt.Scan
	fmt.Scan(&a, &b, &c, &d)

	// Check if the condition is true
	if a*b%2 == 1 && (c+d)%2 == 1 {
		// If the condition is true, print "No" to the output stream
		fmt.Println("No")
	} else {
		// If the condition is false, print "Yes" to the output stream
		fmt.Println("Yes")
	}
}

