package main

import (
	_"bufio" // Importing bufio package but not using it
	"fmt"    // Importing fmt package for formatted I/O
	_"os"    // Importing os package but not using it
	_"strconv" // Importing strconv package but not using it
)

func main() {
	// Declare variables to hold input values
	var x, a, b int
	
	// Read three integer values from standard input
	fmt.Scan(&x, &a, &b)
	
	// Evaluate the difference between b and a to determine the output
	switch {
		// Case when the difference is less than or equal to 0
		case b-a <= 0:
			fmt.Println("delicious") // Output "delicious" if b is less than or equal to a
			break
		// Case when the difference is less than or equal to x
		case b-a <= x:
			fmt.Println("safe") // Output "safe" if the difference is within the limit x
			break
		// Default case when the difference is greater than x
		default:
			fmt.Println("dangerous") // Output "dangerous" if the difference exceeds x
			break
	}
}
