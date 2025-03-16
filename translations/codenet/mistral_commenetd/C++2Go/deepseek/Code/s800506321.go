package main

import (
	"fmt"
)

func main() {
	var n, k, x, y, z int
	// Declare five integer variables: n, k, x, y, and z

	fmt.Scan(&n)
	// Use the fmt.Scan() function to read the first integer (n) from the standard input stream

	fmt.Scan(&k)
	// Use the fmt.Scan() function to read the second integer (k) from the standard input stream

	x = n / k
	// Calculate the integer division of n by k and assign the result to the variable x

	y = n % k
	// Calculate the remainder of n divided by k and assign the result to the variable y

	if y != 0 {
		z = x + 1 - x
		// If the remainder y is non-zero, assign the value 1 to the variable z
	} else {
		z = x - x
		// If the remainder y is zero, assign the value 0 to the variable z
	}
	fmt.Println(z)
	// Use the fmt.Println() function to print the value of z to the standard output stream
}

