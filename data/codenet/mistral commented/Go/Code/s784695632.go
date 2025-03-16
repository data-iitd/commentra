
package main

import "fmt" // Import the "fmt" package for formatted I/O.

func main() {
	// Define the function "main" as the entry point of our program.
	var x, y int

	// Read the values of variables "x" and "y" from the standard input.
	fmt.Scan(&x, &y)

	// Print the result of the expression "x + y/2" to the standard output.
	fmt.Println(x + y/2)

	// End of code.
}