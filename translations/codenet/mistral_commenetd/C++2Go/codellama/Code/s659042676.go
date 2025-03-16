
package main

import (
	"fmt"
)

func main() {
	var a, b int // Declare two integer variables `a` and `b`

	// Read two integer values from the standard input using `fmt.Scan`
	fmt.Scan(&a, &b)

	// Calculate the difference between `6` and the sum of `a` and `b`
	result := 6 - a - b

	// Print the result to the standard output using `fmt.Println`
	fmt.Println(result)
}

