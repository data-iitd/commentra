package main

import (
	"fmt"
)

func main() {
	// Declare variables n, k, and cnt of type int
	var n, k, cnt int

	// Read two integers n and k from the standard input using fmt.Scanf
	fmt.Scanf("%d%d", &n, &k)
	// Initialize variable cnt to zero
	cnt = 0
	// Loop through n times using a for loop
	for n > 0 {
		// Declare variable h of type int
		var h int

		// Read an integer h from the standard input using fmt.Scanf
		fmt.Scanf("%d", &h)
		// If h is greater than or equal to k, increment cnt by 1
		if h >= k {
			cnt++
		}
		n-- // Decrement n
	}
	// Print the value of cnt to the standard output using fmt.Printf
	fmt.Printf("%d\n", cnt)
	// Return 0 to indicate successful execution of the program
}

// <END-OF-CODE>
