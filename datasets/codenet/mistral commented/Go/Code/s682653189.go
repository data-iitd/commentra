package main

// This file is part of the "main" package.

import "fmt"

// The main function is the entry point of the program.
func main(){
	// Initialize a variable "s" of type string.
	var s string

	// Read a single string from the standard input (usually the keyboard) and store it in the variable "s".
	fmt.Scan(&s)

	// Iterate through each character in the string "s" using a for loop.
	for i := 0 ; i < len(s) ; i++ {
		// Print the character at the current index "i" of the string "s" to the standard output (usually the terminal).
		fmt.Print("x")
	}

	// Print a newline character to the standard output.
	fmt.Println("")

	// Indicate the end of the code.
}