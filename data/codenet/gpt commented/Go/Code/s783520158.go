package main

import (
	"fmt"
)

func main() {
	// Declare three integer variables to hold the input values
	var a, b, c int
	
	// Read three integers from standard input
	fmt.Scan(&a, &b, &c)

	// Check if the difference between the first two numbers is equal to the difference between the last two numbers
	if b-a == c-b {
		// If the differences are equal, print "YES"
		fmt.Println("YES")
	} else {
		// If the differences are not equal, print "NO"
		fmt.Println("NO")
	}
}
