package main

import (
	"fmt"
)

func main() {
	// Declare three integer variables 'a', 'b', and 'c'
	var a, b, c int

	// Read three integers from the standard input using fmt.Scanf
	fmt.Scanf("%d %d %d", &a, &b, &c)

	// Check if the condition 'b > a * c' is true
	if b > a*c {
		// If the condition is true, print the value of 'c'
		fmt.Println(c)
	} else {
		// If the condition is false, calculate the integer division of 'b' by 'a'
		// and print the result
		fmt.Println(b / a)
	}
}

// <END-OF-CODE>
