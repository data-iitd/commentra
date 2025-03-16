package main

import "fmt"

func main() {
	// Declare variables A, B, and C of type int
	var A, B, C int

	// Read three integers from the standard input using Scanf function
	fmt.Scanf("%d %d %d", &A, &B, &C)

	// Check if the condition C-A+B is less than zero
	if C-A+B < 0 {
		// If the condition is true, print zero as output
		fmt.Println("0")
	} else {
		// If the condition is false, calculate the value of C-A+B and print it as output
		fmt.Printf("%d\n", C-A+B)
	}
}