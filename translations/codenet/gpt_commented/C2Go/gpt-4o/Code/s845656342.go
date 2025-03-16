package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // Main function where execution starts
	var x int // Declare an integer variable x

	// Read an integer value from user input and store it in x
	fmt.Scanf("%d", &x)

	// Check if the value of x is equal to 1
	if x == 1 {
		fmt.Println("0") // If x is 1, print "0"
	} else {
		fmt.Println("1") // If x is not 1, print "1"
	}
}

// <END-OF-CODE>
