package main

import (
	"fmt"
)

func main() {
	var age int
	// Prompt the user to input their age
	fmt.Scan(&age)

	// Check if the age is equal to 1
	if age == 1 {
		// If age is 1, print 'Hello World'
		fmt.Println("Hello World")
	} else {
		// If age is not 1, prompt the user to input two integers
		var a, b int
		fmt.Scan(&a, &b)
		// Calculate and print the sum of the two integers
		fmt.Println(a + b)
	}
}

// <END-OF-CODE>
