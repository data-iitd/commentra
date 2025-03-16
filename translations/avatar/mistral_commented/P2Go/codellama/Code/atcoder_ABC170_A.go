
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read a list of space-separated integers as input from the standard input
	// and convert each integer to its corresponding Go integer type using the strconv.Atoi() function
	var a []int
	fmt.Scan(&a)

	// Iterate over the elements of the list a using the range keyword
	// which returns the index and the value of each element
	for index, value := range a {
		// Check if the current value is equal to zero
		if value == 0 {
			// Print the index of the first zero to the standard output
			fmt.Println(index + 1)
			// Terminate the loop using the break statement
			break
		}
	}
}

