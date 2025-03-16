package main

import (
	"fmt"
)

func main() {
	// Declare variables A and B to hold input values, and flag to indicate if a condition is met
	var A, B int
	var flag bool

	// Read two integers from user input
	fmt.Scan(&A, &B)

	// Loop through the values 1 to 3
	for i := 1; i <= 3; i++ {
		// Check if the product of A, B, and i is odd
		if (A*B*i)%2 == 1 {
			// Set flag to true if the condition is met and exit the loop
			flag = true
			break
		}
	}

	// Print "Yes" if flag is set, indicating at least one odd product was found; otherwise print "No"
	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

