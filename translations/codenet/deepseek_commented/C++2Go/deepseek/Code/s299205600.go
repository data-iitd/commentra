package main

import (
	"fmt"
)

func main() {
	var a int
	var b int
	fmt.Scan(&a) // Read the value of 'a' from standard input
	fmt.Scan(&b) // Read the value of 'b' from standard input
	var result int

	// Determine the value of 'result' based on the values of 'a' and 'b'
	if a > b {
		result = 2 * a - 1 // If 'a' is greater than 'b', calculate 'result' as 2 * 'a' - 1
	} else if a == b {
		result = 2 * a // If 'a' is equal to 'b', calculate 'result' as 2 * 'a'
	} else {
		result = 2 * b - 1 // If 'a' is less than 'b', calculate 'result' as 2 * 'b' - 1
	}

	fmt.Println(result) // Output the value of 'result' to standard output
}

