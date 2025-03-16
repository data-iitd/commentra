// Import the "fmt" package for formatted I/O
package main

import "fmt"

func main() {
	// Declare three integer variables named A, B, and C
	var A, B, C int

	// Use the "fmt.Scanf" function to read three integers from the standard input
	// and assign them to the variables A, B, and C respectively
	fmt.Scanf("%d %d %d", &A, &B, &C)

	// Check if the value of C is within the range of A and B
	if C >= A && C <= B {
		// If it is, print "Yes" to the standard output
		fmt.Println("Yes")
	} else {
		// Otherwise, print "No" to the standard output
		fmt.Println("No")
	}

	// End of code
}