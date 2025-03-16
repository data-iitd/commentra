package main // Define the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // Define the main function
	var A, B int // Declare two integer variables A and B
	fmt.Scanf("%d %d", &A, &B) // Read two integers from standard input and store them in variables A and B
	if A < 10 && B < 10 { // Check if both A and B are less than 10
		fmt.Println(A * B) // If true, print the product of A and B to standard output
	} else { // If the condition is false
		fmt.Println(-1) // Print -1 to standard output as an error message
	}
} // End of main function
// <END-OF-CODE>
