package main

import (
	"fmt" // Importing the fmt package for formatted I/O operations
)

// comp function compares two integers x and a.
// It returns 0 if x is less than a, otherwise it returns 10.
func comp(x, a int) int {
	// Check if x is less than a
	if x < a {
		return 0 // Return 0 if the condition is true
	} 
	return 10 // Return 10 if x is not less than a
}

func main() {
	var x, a int // Declare two integer variables x and a
	// Read input values for x and a from the user
	fmt.Scan(&x, &a)
	
	// Call the comp function with x and a, and print the result
	fmt.Println(comp(x, a))
}
