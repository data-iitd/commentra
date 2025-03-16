package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a Scanner object to read input from the user
	var x, y, a, b int64
	fmt.Scan(&x, &y, &a, &b)

	// Initialize variables for calculations
	j := 2
	c := int64(math.Max(float64(x), float64(y)))

	// Check if the maximum value exceeds the upper bound b
	if c > b {
		fmt.Println(0) // Output 0 if no valid multiples exist
		return
	}

	// Loop to find the least common multiple (LCM) of x and y
	for c%int64(math.Min(float64(x), float64(y))) != 0 {
		// Multiply by j to find the next multiple
		if x > y {
			c = x * j
			j++
		} else {
			c = y * j
			j++
		}

		// Check if the calculated multiple exceeds the upper bound b
		if c > b {
			fmt.Println(0) // Output 0 if no valid multiples exist
			return
		}
	}

	// If a valid multiple was found within the bounds
	var count int64
	// Find the first multiple of c within the range [a, b]
	for i := a; i <= b; i++ {
		if i%c == 0 {
			break
		}
	}

	// Check if a valid multiple was found within the range
	if i != b+1 {
		// Calculate the number of multiples of c in the range [a, b]
		count = ((b - i) / c) + 1
	} else {
		fmt.Println(0) // Output 0 if no multiples found
		return
	}

	fmt.Println(count)
}

