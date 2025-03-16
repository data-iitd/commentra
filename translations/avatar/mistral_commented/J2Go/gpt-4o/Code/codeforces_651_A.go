package main

import (
	"fmt"
)

func main() {
	// Reading two integers 'a' and 'b' from the standard input
	var a, b int
	fmt.Scan(&a, &b)

	// Initializing variable 'c' to 0
	c := 0

	// Checking if both 'a' and 'b' are equal to 1. If yes, then print 0 and exit
	if a == 1 && b == 1 {
		fmt.Println(0) // Printing 0 as the output
		return         // Exiting the main function
	}

	// If 'a' is not equal to 1 and 'b' is not equal to 1, then perform the following steps
	for a >= 1 || b >= 1 {
		// If 'a' is greater than or equal to 'b', then decrement 'b' and increment 'a' by 2
		if a >= b {
			b++
			a -= 2
		} else {
			// If 'a' is less than 'b', then increment 'a' and decrement 'b' by 2
			a++
			b--
		}

		// Checking if either 'a' or 'b' has become 0. If yes, then increment 'c' and break the loop
		if a <= 0 || b <= 0 {
			c++
			break
		}

		// Incrementing 'c' for each iteration of the loop
		c++
	}

	// Printing the final result 'c' as the output
	fmt.Println(c)
}

// Static method for swapping two integers (not used in this code)
// func swap(a, b int) (int, int) {
// 	return b, a
// }

// Static method for debugging purposes (not used in this code)
// func debug(obj ...interface{}) {
// 	fmt.Println(obj)
// }
