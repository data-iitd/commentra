package main

import (
	"fmt"
	"math"
)

func main() {
	// Declare variables a, b, c, and d of type int
	var a, b, c, d int

	// Read values of variables a, b, c, and d from standard input
	fmt.Scan(&a, &b, &c, &d)

	// Calculate the difference between a and c, and the difference between b and d
	difference_ab := int64(a) - int64(c)
	difference_cd := int64(b) - int64(d)

	// Multiply the differences and print the result to standard output
	fmt.Println(difference_ab * difference_cd)
}

