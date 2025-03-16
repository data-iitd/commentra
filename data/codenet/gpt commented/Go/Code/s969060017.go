package main

import "fmt"

func main() {
	// Declare two integer variables a and b
	var a, b int
	
	// Read two integer values from standard input
	fmt.Scan(&a, &b)

	// Check if b is divisible by a
	if b%a == 0 {
		// If b is divisible by a, print the sum of a and b
		fmt.Println(a + b)
	} else {
		// If b is not divisible by a, print the difference between b and a
		fmt.Println(b - a)
	}
}
