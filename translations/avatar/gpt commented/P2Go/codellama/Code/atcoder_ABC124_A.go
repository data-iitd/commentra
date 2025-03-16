package main

import "fmt"

func main() {
	// Read two integers from input and assign them to variables a and b
	var a, b int
	fmt.Scan(&a, &b)

	// Initialize a variable c to accumulate the result
	var c int

	// Loop for 2 iterations
	for i := 0; i < 2; i++ {
		// Add the maximum of a and b to c
		c += max(a, b)

		// Decrease the larger of the two numbers (a or b) by 1
		if a >= b {
			a-- // If a is greater than or equal to b, decrement a
		} else {
			b-- // Otherwise, decrement b
		}
	}

	// Print the final accumulated value of c
	fmt.Println(c)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

