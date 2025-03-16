package main

import (
	"fmt"
)

func main() {
	var a, b, c int // Declare and initialize three integer variables

	// Read the values of a, b, and c from the standard input using fmt.Scan
	fmt.Scan(&a, &b, &c)

	if a + b >= c { // Check if the sum of a and b is greater than or equal to c
		fmt.Println("Yes") // If the condition is true, print the string "Yes" to the standard output
	} else {
		fmt.Println("No") // If the condition is false, print the string "No" to the standard output
	}
}

