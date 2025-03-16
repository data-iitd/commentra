package main

import (
	"fmt" // Import the fmt package for formatted I/O operations
)

func main() {
	var a, b, c int // Declare three integer variables to hold the input values

	// Read three integers from the user
	fmt.Scan(&a, &b, &c)

	// Check if any two of the three numbers sum up to the third number
	// If a + b equals c, or b + c equals a, or a + c equals b, print "Yes"
	// Otherwise, print "No"
	if a+b == c || b+c == a || a+c == b {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

