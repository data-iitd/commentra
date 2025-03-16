package main
// Import the main package.

import (
	"fmt"
	// Import the fmt package for formatted I/O.
)

func main() {
	var x int
	// Declare an integer variable x.
	fmt.Scan(&x)
	// Use the Scan function to take an integer input from the user and assign it to the variable x.
	fmt.Println(x * x * x)
	// Use the Println function to display the result of the computation x*x*x on the console.
	// Add a newline character to the output.
}
// <END-OF-CODE>
