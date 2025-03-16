package main

import (
	"fmt"
)

func main() {
	// Declare three integer variables: a, b, and c
	var a, b, c int

	// Use fmt.Scanf to read three integers from the standard input and store them in variables a, b, and c
	fmt.Scanf("%d %d %d", &a, &b, &c)

	// Check if the condition a < b and b < c is true. If it is, print "Yes". Otherwise, print "No"
	if a < b && b < c {
		fmt.Println("Yes") // If the condition is true, print "Yes"
	} else {
		fmt.Println("No") // If the condition is false, print "No"
	}
}

// <END-OF-CODE>
