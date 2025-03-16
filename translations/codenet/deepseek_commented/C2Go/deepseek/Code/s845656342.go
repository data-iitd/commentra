package main

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() {
	var x int // Declare an integer variable
	fmt.Scan(&x) // Read an integer value from the user

	if x == 1 { // Implement a simple if-else statement
		fmt.Println("0") // Print 0 if the input is 1
	} else {
		fmt.Println("1") // Print 1 if the input is not 1
	}
}

