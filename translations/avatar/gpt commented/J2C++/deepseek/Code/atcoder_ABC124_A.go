package main

import (
	"fmt"
)

func main() {
	// Reading two integers from the user
	var a, b int
	fmt.Scan(&a, &b)
	
	sum := 0 // Initializing a variable to hold the sum of selected integers
	
	// Loop to iterate twice to calculate the sum
	for i := 0; i < 2; i++ {
		// Check if 'a' is greater than or equal to 'b'
		if a >= b {
			sum += a // Add 'a' to the sum
			a-- // Decrement 'a' by 1
		} else {
			sum += b // Add 'b' to the sum
			b-- // Decrement 'b' by 1
		}
	}
	
	// Output the final sum to the console
	fmt.Println(sum)
}
