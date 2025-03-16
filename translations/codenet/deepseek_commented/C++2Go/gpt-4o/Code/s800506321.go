package main // Define the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // Define the main function
	var n, k, x, y, z int // Declare five integer variables to store values
	fmt.Scan(&n) // Read an integer value for n from the standard input
	fmt.Scan(&k) // Read an integer value for k from the standard input
	x = n / k // Calculate the integer division of n by k and store the result in x
	y = n % k // Calculate the remainder of the integer division of n by k and store the result in y
	if y != 0 { // Check if the remainder y is not equal to 0
		z = x + 1 - x // If y is not equal to 0, calculate z as x+1-x
	} else { // If y is equal to 0
		z = x - x // Calculate z as x-x
	}
	fmt.Println(z) // Print the value of z to the standard output
}
