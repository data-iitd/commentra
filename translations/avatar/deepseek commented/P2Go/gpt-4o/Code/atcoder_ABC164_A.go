package main

import (
	"fmt"
)

func main() {
	var S, W int
	// Read the values of S and W from a single line of input
	fmt.Scan(&S, &W)
	// Check if the value of W is greater than or equal to S
	// If true, print "unsafe"
	if S <= W {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}

// <END-OF-CODE>
