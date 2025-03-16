package main

import (
	"fmt"
	"math"
)

func main() {
	// Declare two integer variables to store input values
	var x, y int

	// Read two integer values from standard input
	fmt.Scan(&x, &y)

	// Check if the absolute difference between x and y is less than or equal to 1
	if math.Abs(float64(x-y)) <= 1 {
		// If the condition is true, output "Brown"
		fmt.Println("Brown")
	} else {
		// If the condition is false, output "Alice"
		fmt.Println("Alice")
	}
}

