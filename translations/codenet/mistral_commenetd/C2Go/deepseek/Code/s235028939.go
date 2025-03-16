package main

import (
	"fmt" // Import the fmt package for formatted I/O operations
)

func main() {
	// Declare two integer variables n and m
	var n, m int

	// Use the fmt.Scan function to read two integers from the standard input and store them in n and m variables
	fmt.Scan(&n, &m)

	// Calculate the product of (n - 1) and (m - 1) and store the result in the variable result
	result := (n - 1) * (m - 1)

	// Use the fmt.Println function to print the result to the standard output
	fmt.Println(result)

	// Flush the output buffer to ensure that all the data is written to the standard output before the program terminates
	// Note: In Go, the output buffer is automatically flushed when fmt.Println is used
}
