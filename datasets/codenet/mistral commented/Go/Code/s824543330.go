// Import the "fmt" package for formatted I/O
package main

import "fmt"

func main() {
	// Declare and initialize two integer variables, a and b, using fmt.Scan
	var a, b int
	fmt.Scan(&a, &b)

	// Check if the product of a and b is even using the modulo operator (%).
	// If the result is zero, it means that a and b are both even or one of them is even and the other is a multiple of 2.
	if a*b%2 == 0 {
		// If the condition is true, print the message "Even"
		fmt.Println("Even")
	} else {
		// If the condition is false, print the message "Odd"
		fmt.Println("Odd")
	}
}

// End of code
