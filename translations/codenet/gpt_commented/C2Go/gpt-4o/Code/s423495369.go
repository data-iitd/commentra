package main

import (
	"fmt"
)

func main() {
	// Declare three integer variables A, B, and C
	var A, B, C int

	// Read three integers from user input and store them in A, B, and C
	fmt.Scanf("%d %d %d", &A, &B, &C)

	// Check if C is between A and B (A < C < B)
	if A < C && C < B {
		// If true, print "Yes"
		fmt.Println("Yes")
	} 
	// Check if C is between B and A (A > C > B)
	else if A > C && C > B {
		// If true, print "Yes"
		fmt.Println("Yes")
	} 
	// If neither condition is met, print "No"
	else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
