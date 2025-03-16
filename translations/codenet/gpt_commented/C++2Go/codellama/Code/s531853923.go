package main

import (
	"fmt"
)

func main() {
	// Declare four integer variables to hold input values
	var a, b, c, d int

	// Read four integer values from user input
	fmt.Scan(&a, &b, &c, &d)

	// Check if the product of a and b is odd and the sum of c and d is odd
	if a*b%2 == 1 && (c+d)%2 == 1 {
		// If both conditions are true, output "No"
		fmt.Println("No")
	} else {
		// If either condition is false, output "Yes"
		fmt.Println("Yes")
	}
}

