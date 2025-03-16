
package main

import "fmt"

// Define the main function as the entry point of our program
func main() {
	// Declare and initialize three integer variables "a", "b", and "c"
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	// Check if the value of "c" is within the range of "a" and "b"
	if c >= a && c <= b {
		// If the condition is true, print the string "Yes" to the standard output
		fmt.Println("Yes")
	} else {
		// If the condition is false, print the string "No" to the standard output
		fmt.Println("No")
	}
}

