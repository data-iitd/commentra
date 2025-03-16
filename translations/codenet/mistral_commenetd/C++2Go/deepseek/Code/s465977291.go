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
	a := float64(d*2 + 1)

	// Use the math.Ceil function to find the smallest integer greater than or equal to the result of dividing 'n' by 'a'
	// Print the result to the standard output
	fmt.Println(math.Ceil(float64(n) / a))
}

