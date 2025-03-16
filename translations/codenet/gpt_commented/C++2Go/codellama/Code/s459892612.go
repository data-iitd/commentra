package main

import (
	"fmt"
	"os"
)

func main() {
	// Declare three integer variables to hold input values
	var a, b, c int

	// Read three integers from standard input
	fmt.Fscan(os.Stdin, &a, &b, &c)

	// Check if the sum of a and b is greater than or equal to c
	if a+b >= c {
		// If the condition is true, print "Yes"
		fmt.Println("Yes")
	} else {
		// If the condition is false, print "No"
		fmt.Println("No")
	}

	// Return 0 to indicate successful completion of the program
	os.Exit(0)
}

