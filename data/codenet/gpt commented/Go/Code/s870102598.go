package main

import "fmt"

func main() {
	// Declare three integer variables a, b, and c
	var a, b, c int
	
	// Read input values for a, b, and c from the user
	fmt.Scan(&a, &b, &c)

	// Check if c is within the range [a, b]
	if c >= a && c <= b {
		// If c is within the range, print "Yes"
		fmt.Println("Yes")
	} else {
		// If c is outside the range, print "No"
		fmt.Println("No")
	}
}
