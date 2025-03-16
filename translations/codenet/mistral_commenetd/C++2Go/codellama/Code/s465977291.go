
package main

import (
	"fmt"
	"math"
)

func main() {
	// Read two integers 'n' and 'd' from the standard input
	var n, d int
	fmt.Scan(&n, &d)

	// Calculate the value of 'a' as 'd' multiplied by 2 and adding 1
	a := d*2 + 1

	// Use the ceil function to find the smallest integer greater than or equal to the result of dividing 'n' by 'a'
	// Print the result to the standard output
	fmt.Println(math.Ceil(float64(n) / a))

	// Return 0 to indicate successful execution of the program
	return
}

