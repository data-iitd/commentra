package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // The entry point of the program
	var a, b int // Declare two integer variables 'a' and 'b'

	fmt.Scanf("%d %d", &a, &b) // Read two integers from the standard input and store them in variables 'a' and 'b'

	fmt.Println((b-1)+(a-2)/(a-1)) // Print the result of the expression ((b-1)+(a-2))/(a-1) to the standard output
}

// <END-OF-CODE>
