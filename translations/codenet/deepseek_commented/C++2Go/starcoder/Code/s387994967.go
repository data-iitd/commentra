<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare two integer variables A and B to store user input
	var A, B int

	// Read two integers from the standard input (cin) and store them in A and B
	fmt.Scanf("%d %d", &A, &B)

	// Check if A is between 6 and 12 (inclusive)
	if A >= 6 && A < 13 {
		// If true, calculate B/2 and print the result
		fmt.Println(B / 2)
	}

	// Check if A is less than 6
	if A < 6 {
		// If true, print 0
		fmt.Println(0)
	}

	// Check if A is 13 or more
	if A >= 13 {
		// If true, print the value of B
		fmt.Println(B)
	}
}

