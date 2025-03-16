package main

import (
	"fmt"
)

func main() {
	var a, b int
	
	// Read two integers a and b from the user
	fmt.Scanf("%d %d", &a, &b)
	
	// Compute a value based on these inputs
	result := ((b - 1) + (a - 2)) / (a - 1)
	
	// Print the computed value
	fmt.Println(result)
}

// <END-OF-CODE>
