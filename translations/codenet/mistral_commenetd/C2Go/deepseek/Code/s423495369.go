package main

import (
	"fmt"
)

func main() {
	var A, B, C int

	// Read three integers from the standard input using fmt.Scan function
	fmt.Scan(&A, &B, &C)

	// Check if A is less than C and C is less than B
	if A < C && C < B {
		// If condition is true, print "Yes" to the standard output
		fmt.Println("Yes")
	} // End of first if block
	// Else if condition checks if A is greater than C and C is greater than B
	else if A > C && C > B {
		// If condition is true, print "Yes" to the standard output
		fmt.Println("Yes")
	} // End of second if block
	// Else condition is executed when neither first nor second condition is true
	else {
		// If condition is false, print "No" to the standard output
		fmt.Println("No")
	} // End of else block
} // End of main function

