// Import the "fmt" package for formatted I/O
package main

import "fmt"

func main() {
	// Declare and initialize two integer variables "a" and "b"
	// by reading input values from the standard input using the "fmt.Scan" function
	var a, b int
	fmt.Scan(&a, &b)

	// Calculate the product of "a" and "b" and store it in a new variable "product"
	if product, ok := a * b; ok {
		// Check if the product is even or odd using an if statement
		if product % 2 == 0 {
			// If the product is even, print the message "Even" to the standard output
			fmt.Println("Even")
		} else {
			// If the product is odd, print the message "Odd" to the standard output
			fmt.Println("Odd")
		}
	}
}

// End of code
