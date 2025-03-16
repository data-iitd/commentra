package main // Define the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // Define the main function
	var A, B int // Declare two integer variables A and B
	fmt.Scanf("%d %d", &A, &B) // Read two integers from the user and store them in A and B
	if A < 10 && B < 10 { // Check if both A and B are less than 10
		fmt.Println(A * B) // If true, print the multiplication result
	} else {
		fmt.Println(-1) // If the condition is false, print -1
	}
} // Return 0 is implicit in Go when the program ends
// <END-OF-CODE>
