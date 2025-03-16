package main

import (
	"fmt"
)

func main() {
	// Read an integer input from the user
	var n int
	fmt.Scan(&n)

	// Continuously divide n by 2 while it is even
	for n%2 == 0 {
		n /= 2
	}

	// Check if the resulting value of n is 1
	if n == 1 {
		// If n is 1, it means the original number was a power of 2
		fmt.Println("YES")
	} else {
		// If n is not 1, the original number was not a power of 2
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
