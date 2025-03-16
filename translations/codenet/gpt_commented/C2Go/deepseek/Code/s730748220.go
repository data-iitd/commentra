package main

import (
	"fmt"
)

func main() {
	var i, j, k, n int // Declare integer variables i, j, k, and n
	
	// Read an integer input from the user
	fmt.Scan(&n)
	
	// Calculate and print the result based on the input n
	// The expression (24 + (24 - n)) simplifies to (48 - n)
	fmt.Println(24 + (24 - n))
}

