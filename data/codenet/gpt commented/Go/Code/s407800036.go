package main

import "fmt"

func main() {
	// Declare variables A, B, and C to hold integer values
	var A, B, C int
	
	// Read three integers from standard input
	fmt.Scanf("%d %d %d", &A, &B, &C)

	// Check if C is within the range defined by A and B (inclusive)
	if C >= A && C <= B {
		// If C is within the range, print "Yes"
		fmt.Println("Yes")
	} else {
		// If C is outside the range, print "No"
		fmt.Println("No")
	}
}
