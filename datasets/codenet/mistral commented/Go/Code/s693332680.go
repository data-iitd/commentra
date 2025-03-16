// Importing necessary packages
package main

import (
	_"bufio"
	"fmt"
	_"os"
	_"strconv"
)

// Declaring variables
func main() {
	var x, a, b int

	// Reading input values from standard input
	fmt.Scan(&x, &a, &b)

	// Logic block to check if b is less than or equal to a
	switch {
		// Base case: If b is less than or equal to a
		case b-a <= 0:
			fmt.Println("delicious")
			break

		// Next case: If b is greater than a but less than or equal to x
		case b-a <= x:
			fmt.Println("safe")
			break

		// Default case: If none of the above conditions are met
		default:
			fmt.Println("dangerous")
			break
	}
}

// End of code
