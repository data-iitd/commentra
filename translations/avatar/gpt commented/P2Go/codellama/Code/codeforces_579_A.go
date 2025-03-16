
package main

import (
	"fmt"
	"math"
)

func main() {
	// Read an integer input from the user
	var n int
	fmt.Scan(&n)

	// Initialize a counter variable to track the number of iterations
	x := 1

	// Continue looping while n is not a power of 2
	for math.Log2(float64(n))%1 != 0 {
		x++ // Increment the counter for each iteration
		// Subtract the largest power of 2 less than or equal to n from n
		n -= int(math.Pow(2, math.Floor(math.Log2(float64(n)))))
	}

	// Print the final count of iterations
	fmt.Println(x)
}

