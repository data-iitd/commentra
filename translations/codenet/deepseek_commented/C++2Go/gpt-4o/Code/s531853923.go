package main

import (
	"fmt"
)

func main() {
	// Declare four integer variables to store user input
	var a, b, c, d int
	
	// Read four integers from the standard input
	fmt.Scan(&a, &b, &c, &d)
	
	// Check if the product of a and b is odd and if the sum of c and d is also odd
	if (a*b)%2 == 1 && (c+d)%2 == 1 {
		// If both conditions are true, print "No"
		fmt.Println("No")
	} else {
		// Otherwise, print "Yes"
		fmt.Println("Yes")
	}
}

// <END-OF-CODE>
