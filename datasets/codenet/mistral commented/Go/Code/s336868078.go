// Importing required packages
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Creating a new buffered reader from os.Stdin
var in = bufio.NewReader(os.Stdin)

// Function to find the solution
func solve(a, b, c int) int {
	// Declaring a temporary variable
	var temp_ int

	// Checking if c is equal to the sum of a and b
	if c == a+b {
		// If true, then calculate the value of temp_
		temp_ = b + c
		// Add a comment explaining the logic
		// temp_ = b + c; // c is equal to the sum of a and b
	} else if c-1 > a+b {
		// Else if c is greater than the sum of a and b by 1
		// Calculate the difference between c and the sum of a and b
		temp := c - (a + b)
		// Calculate the value of temp_
		temp_ = b + c - temp
		// Add a comment explaining the logic
		// temp_ = b + c - (c - (a + b)); // c is greater than the sum of a and b by 1
	} else {
		// Else, c is less than or equal to the sum of a and b
		// Calculate the value of temp_
		temp_ = b + c
		// Add a comment explaining the logic
		// temp_ = b + c; // c is less than or equal to the sum of a and b
	}

	// Return the value of temp_ as the answer
	return temp_
}

// Main function to read input and call the solve function
func main() {
	// Declaring variables a, b, and c to read input
	var a, b, c int
	// Reading input from stdin using fmt.Fscanf
	fmt.Fscanf(in, "%d %d %d¥n", &a, &b, &c)
	// Calling the solve function and storing the result in ans
	ans := solve(a, b, c)
	// Printing the answer using fmt.Println
	fmt.Println(ans)
	// Add a comment explaining the logic
	// ans := solve(a, b, c); // Solving the problem using the solve function
}

// End of the code
