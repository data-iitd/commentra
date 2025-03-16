// Import the "fmt" package for formatted I/O
package main

import "fmt"

func main() {
	// Declare and initialize three integer variables "a", "b", and "c"
	// with values read from the standard input using the Scanf function
	var a, b, c int
	fmt.Scanf("%d %d %d", &a, &b, &c)

	// Check if the condition "a < b && b < c" is true using an if statement
	if a < b && b < c {
		// If the condition is true, print the string "Yes" to the standard output
		fmt.Println("Yes")
	} else {
		// If the condition is false, print the string "No" to the standard output
		fmt.Println("No")
	}

	// Return from the main function
	return
}

// End of code
