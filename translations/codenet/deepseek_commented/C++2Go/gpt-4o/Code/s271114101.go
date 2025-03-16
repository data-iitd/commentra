package main

import (
	"fmt"
)

func main() {
	// Declare three integer variables 'a', 'b', and 'c'
	var a, b, c int
	
	// Read three integers from the standard input and store them in 'a', 'b', and 'c'
	fmt.Scan(&a, &b, &c)
	
	// Check if any of the following conditions are true:
	// - a + b equals c
	// - b + c equals a
	// - a + c equals b
	if a+b == c || b+c == a || a+c == b {
		// If any of these conditions are true, print "Yes"
		fmt.Println("Yes")
	} else {
		// Otherwise, print "No"
		fmt.Println("No")
	}
}

// <END-OF-CODE>
