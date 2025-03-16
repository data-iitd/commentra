package main

import "fmt"

func main() {
	// Declare three integer variables to hold the input values
	var a, b, c int
	
	// Read three integers from standard input
	fmt.Scanf("%d %d %d", &a, &b, &c)
	
	// Check if the integers are in strictly increasing order
	if a < b && b < c {
		// If they are in increasing order, print "Yes"
		fmt.Println("Yes")
	} else {
		// If they are not in increasing order, print "No"
		fmt.Println("No")
	}
	
	// End of the main function
	return
}
