package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // The main function is the entry point of the program
	var A, B int // Declare two integer variables A and B
	fmt.Scan(&A, &B) // Take input from the user for variables A and B
	C := A + B // Calculate the sum of A and B and store it in variable C

	// Check if neither A, B, nor the sum C is divisible by 3
	if A%3 != 0 && B%3 != 0 && C%3 != 0 {
		fmt.Println("Impossible") // If the condition is true, print "Impossible" to the console
	} else {
		fmt.Println("Possible") // Otherwise, print "Possible" to the console
	}
}

// <END-OF-CODE>
