package main

import (
	"fmt"
	"math"
)

func main() {
	var x, y int64

	// Read user inputs from standard input using fmt.Scan
	fmt.Scan(&x, &y)

	// Check if the absolute difference between x and y is less than or equal to 1
	if math.Abs(float64(x-y)) <= 1 {
		// If the condition is true, print "Brown" to the standard output
		fmt.Println("Brown")
	} else {
		// If the condition is false, print "Alice" to the standard output
		fmt.Println("Alice")
	}
}
