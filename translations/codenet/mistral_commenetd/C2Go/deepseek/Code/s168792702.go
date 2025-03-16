package main

import (
	"fmt"
)

func main() {
	// Declare three integer variables: a, b, and c
	var a, b, c int

	// Use the fmt.Scan function to read three integers from the standard input and store them in variables a, b, and c
	fmt.Scan(&a, &b, &c)

	// Check if the condition a < b and b < c is true. If it is, print "Yes" to the standard output using the fmt.Println function. Otherwise, print "No"
	if a < b && b < c {
		fmt.Println("Yes") // If the condition is true, print "Yes"
	} else {
		fmt.Println("No") // If the condition is false, print "No"
	}
}

