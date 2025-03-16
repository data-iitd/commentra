package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() {
	var N, A int // Define two integer variables: N and A

	// Read the values of N and A from the standard input
	fmt.Scan(&N, &A)

	// Use a conditional statement to check if the remainder of N divided by 500 is less than or equal to A
	if N%500 <= A {
		fmt.Println("Yes") // Print "Yes" if the condition is true
	} else {
		fmt.Println("No") // Print "No" if the condition is false
	}
}

// <END-OF-CODE>
