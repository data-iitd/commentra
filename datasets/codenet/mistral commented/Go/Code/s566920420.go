
package main

import (
	"fmt" // Import the "fmt" package for formatted I/O
)

func main() {
	// Declare a variable named "a" of type int
	var a int

	// Read a value of type int from the standard input and store it in the variable "a"
	fmt.Scan(&a)

	// Calculate the result of the expression "a + a*a + a*a*a"
	result := a + a*a + a*a*a

	// Print the result to the standard output
	fmt.Println(result)

	// End of code
}	