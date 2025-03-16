package main

import (
	"fmt" // Import the fmt package for formatted I/O operations
)

func main() {
	var r int // Declare an integer variable to store the input
	fmt.Scan(&r) // Read an integer input from the user

	fmt.Println(r * r) // Calculate the square of the input and output the result
}

