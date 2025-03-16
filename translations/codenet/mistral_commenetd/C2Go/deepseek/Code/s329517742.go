package main

import (
	"fmt" // Importing the format package for formatted I/O operations
)

func main() {
	var a, b int // Declaring two integer variables a and b
	fmt.Scan(&a, &b) // Reading two integers from the standard input and storing them in variables a and b

	// Logical block to check if 500 times the value of variable 'a' is greater than or equal to the value of variable 'b'
	if 500*a >= b {
		fmt.Println("Yes") // If the condition is true, print 'Yes' to the standard output
	} else {
		fmt.Println("No") // If the condition is false, print 'No' to the standard output
	}
}

