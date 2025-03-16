package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b) // Read first and second integer input
	c := 0           // Initialize counter

	if a == 1 && b == 1 { // Check if both a and b are 1
		fmt.Println(0) // Print 0 if true
	} else {
		for a >= 1 || b >= 1 { // Continue until a or b is less than or equal to 0
			if a >= b { // If a is greater than or equal to b
				b++    // Increment b
				a -= 2 // Decrement a by 2
			} else { // If b is greater than a
				a++    // Increment a
				b -= 2 // Decrement b by 2
			}
			if a <= 0 || b <= 0 { // Check if either a or b is less than or equal to 0
				c++ // Increment counter and break the loop
				break
			}
			c++ // Increment counter in each iteration
		}
		fmt.Println(c) // Print the final value of counter
	}
}

// Utility method to swap two integers (not used in this code)
// func swap(a, b int) (int, int) {
// 	return b, a
// }

// Utility method for debugging (not used in this code)
// func debug(obj ...interface{}) {
// 	fmt.Println(obj)
// }

