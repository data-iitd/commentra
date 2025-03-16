package main

import (
	"fmt"
	"math"
)

func main() {
	// Read a long integer N from user input
	var N int64
	fmt.Scan(&N)

	// Initialize a variable to hold the minimum value
	min := int64(0)

	// Loop to read five long integers and find the minimum
	for i := 0; i < 5; i++ {
		// For the first iteration, directly assign the value to min
		if i == 0 {
			fmt.Scan(&min)
		} else {
			// For subsequent iterations, update min if a smaller value is found
			var temp int64
			fmt.Scan(&temp)
			if temp < min {
				min = temp
			}
		}
	}

	// Calculate the result by dividing N by min, rounding up, and adding 4
	result := int64(math.Ceil(float64(N)/float64(min))) + 4
	fmt.Println(result)
}

