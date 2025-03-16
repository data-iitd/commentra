package main

import (
	"bufio"
	"fmt"
	"os"
)

// Create a buffered reader to read input from standard input
var in = bufio.NewReader(os.Stdin)

// Function to solve the problem based on the given parameters a, b, and c
func solve(a, b, c int) int {
	var temp_ int
	
	// Check if c is equal to the sum of a and b
	if c == a+b {
		// If true, calculate the result as b + c
		temp_ = b + c
	} else if c-1 > a+b {
		// If c-1 is greater than the sum of a and b, calculate the difference
		temp := (c - 1) - (a + b)
		// Adjust the result based on the calculated difference
		temp_ = b + c - temp
	} else {
		// If neither condition is met, simply return b + c
		temp_ = b + c
	}
	 
	// Return the calculated result
	return temp_
}

func main() {
	var a, b, c int
	
	// Read three integers from standard input
	fmt.Fscanf(in, "%d %d %d¥n", &a, &b, &c)

	// Call the solve function with the input values and store the result
	ans := solve(a, b, c)
	
	// Print the result to standard output
	fmt.Println(ans)
}
