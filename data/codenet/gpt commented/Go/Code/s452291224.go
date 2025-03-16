package main

import "fmt"

func main() {
	// Declare three integer variables A, B, and C
	var A, B, C int
	
	// Read three integer values from standard input and store them in A, B, and C
	fmt.Scanf("%d %d %d", &A, &B, &C)
	
	// Check if the expression C - A + B is less than 0
	if C-A+B < 0 {
		// If the expression is less than 0, print "0"
		fmt.Println("0")
	} else {
		// If the expression is 0 or greater, print the result of C - A + B
		fmt.Printf("%d\n", C-A+B)
	}
}
