
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare and initialize two integer variables, x and a
	var x, a int

	// Read data from the standard input stream and store it into x and a
	fmt.Scanf("%d %d", &x, &a)

	// Check if x is greater than or equal to a
	result := 0
	if x >= a {
		result = 1
	}

	// Multiply the result by 10
	result *= 10

	// Print the result to the standard output stream
	fmt.Printf("%d\n", result)
}

