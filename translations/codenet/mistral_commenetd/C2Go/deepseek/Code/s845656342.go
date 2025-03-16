package main

import (
	"fmt"  // Import the fmt package for formatted I/O operations
)

func main() {
	var x int  // Declare an integer variable named x

	// Read an integer value from the standard input and store it in the variable x
	fmt.Scan(&x)

	if x == 1 {  // Check if the value of x is equal to 1
		fmt.Println("0")  // If x is 1, print 0 to the standard output
	} else {  // If x is not equal to 1
		fmt.Println("1")  // Otherwise, print 1 to the standard output
	}
}

