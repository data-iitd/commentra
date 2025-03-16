package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // The entry point of the program
	var h, r int // Declare two integer variables h and r
	fmt.Scanf("%d%d", &h, &r) // Read two integers from the standard input and store them in variables h and r

	if r > -h { // Check if r is greater than the negative value of h
		fmt.Println("1") // If the condition is true, print the number 1 followed by a newline character
	} else if r == -h { // Check if r is equal to the negative value of h
		fmt.Println("0") // If the condition is true, print the number 0 followed by a newline character
	} else { // If the previous conditions are false
		fmt.Println("-1") // Print the number -1 followed by a newline character
	}
} // Indicate that the program has run successfully and terminate the execution
// <END-OF-CODE>
