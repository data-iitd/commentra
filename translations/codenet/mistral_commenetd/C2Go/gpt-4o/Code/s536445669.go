package main

import (
	"fmt"
)

func main() {
	// Declare two integer variables 'n' and 'k'
	var n, k int

	// Read two integers from the standard input using fmt.Scan
	fmt.Scan(&n, &k)

	// Check if 'n' is divisible by 'k'
	if n%k == 0 {
		// If it is, print '0' to the standard output
		fmt.Println("0")
	} else {
		// If it's not, print '1' to the standard output
		fmt.Println("1")
	}
}

// <END-OF-CODE>
