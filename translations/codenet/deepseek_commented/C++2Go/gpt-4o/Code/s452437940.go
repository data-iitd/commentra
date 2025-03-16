package main

import (
	"fmt"
)

func main() {
	// Declare variables to store user input
	var a, b, x int64
	
	// Read three int64 integers from standard input
	fmt.Scanf("%d %d %d", &a, &b, &x)
	
	// Calculate the number of multiples of x between a and b inclusive
	s := (b / x) - (a / x)
	
	// Check if a is a multiple of x and adjust the count accordingly
	if a%x == 0 {
		s++
	}
	
	// Print the result
	fmt.Println(s)
}

// <END-OF-CODE>
