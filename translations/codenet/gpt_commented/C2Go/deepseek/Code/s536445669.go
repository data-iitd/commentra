package main

import (
	"fmt"
)

func main() {
	// Declare two integer variables n and k
	var n, k int

	// Read two integers from user input
	fmt.Scan(&n, &k)

	// Check if n is divisible by k
	if n % k == 0 {
		// If n is divisible by k, print 0
		fmt.Println("0")
	} else {
		// If n is not divisible by k, print 1
		fmt.Println("1")
	}
}

