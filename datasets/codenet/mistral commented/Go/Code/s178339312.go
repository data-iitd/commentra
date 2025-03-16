// Import the "fmt" package for formatted I/O
package main

import "fmt"

func main() {
	// Declare a variable named x of type int
	var x int

	// Read an integer value from the standard input and assign it to the variable x
	fmt.Scan(&x)

	// Print the result of x cubed (x*x*x)
	fmt.Println(x * x * x)
}

// End of code
