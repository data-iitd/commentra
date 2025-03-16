package main

import (
	"fmt"
)

func main() {
	// Declare three integer variables A, B, and C
	var A, B, C int

	// Read three integers from user input and store them in A, B, and C
	fmt.Scan(&A, &B, &C)

	// Check if C is between A and B (A < C < B)
	if A < C && C < B {
		// If true, print "Yes"
		fmt.Println("Yes")
	} else if A > C && C > B {
		// If true, print "Yes"
		fmt.Println("Yes")
	} else {
		// If neither condition is met, print "No"
		fmt.Println("No")
	}
}

