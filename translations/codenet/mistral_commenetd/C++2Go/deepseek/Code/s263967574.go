package main

import (
	"fmt" // Import the fmt package for formatted I/O operations
)

func main() { // Beginning of the main function
	var x int // Declare an integer variable named x

	fmt.Scan(&x) // Read an integer value from the standard input and store it in variable x

	if x >= 1200 { // Beginning of the if statement block
		fmt.Println("ARC") // Output the string "ARC" to the standard output if the condition is true
	} else { // Beginning of the else statement block
		fmt.Println("ABC") // Output the string "ABC" to the standard output if the condition is false
	}
}

