package main

import (
	"fmt" // Import the "fmt" package for formatted I/O
)

func main() {
	// Declare three integer variables "a", "b", and "c"
	var a, b, c int

	// Read three integers from the standard input and assign them to the variables
	fmt.Scan(&a, &b, &c)

	// Check if the difference between "b" and "a" is equal to the difference between "c" and "b"
	if b-a == c-b {
		// If the condition is true, print "YES" to the standard output
		fmt.Println("YES")
	} else {
		// If the condition is false, print "NO" to the standard output
		fmt.Println("NO")
	}

	// End of the code
}