package main

import (
	"fmt"
)

func main() {
	// Initialize three integer variables 'a', 'b', and 'c'
	var a, b, c int

	// Read values of 'a', 'b', and 'c' from the standard input
	fmt.Scan(&a, &b, &c)

	// Check if the given condition is true
	if (100*a + 10*b + c) % 4 == 0 {
		// If the condition is true, print 'YES' to the standard output
		fmt.Println("YES")
	} else {
		// If the condition is false, print 'NO' to the standard output
		fmt.Println("NO")
	}
}

