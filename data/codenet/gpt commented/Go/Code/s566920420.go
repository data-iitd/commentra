package main

import (
	"fmt" // Importing the fmt package for formatted I/O operations
)

func main() {
	var a int // Declare a variable 'a' of type int to store user input
	fmt.Scan(&a) // Read an integer value from standard input and store it in 'a'
	
	// Calculate the expression a + a^2 + a^3 and print the result
	fmt.Println(a + a*a + a*a*a) 
}
