package main

import "fmt"

func main() {
	// Declare variables K and X to hold input values
	var K, X int
	
	// Read two integers from standard input
	fmt.Scan(&K, &X)
	
	// Check if 500 times K is greater than or equal to X
	if 500*K >= X {
		// If the condition is true, print "Yes"
		fmt.Println("Yes")
	} else {
		// If the condition is false, print "No"
		fmt.Println("No")
	}
}
