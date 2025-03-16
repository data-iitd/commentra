package main

import (
	"fmt"
	"math"
)

func main() {
	var N int64
	fmt.Scan(&N)

	// Initialize min to 0 and find the minimum of the first five inputs
	var min int64
	for i := 0; i < 5; i++ {
		var input int64
		fmt.Scan(&input)
		if i == 0 {
			min = input
		} else {
			if input < min {
				min = input
			}
		}
	}

	// Calculate the result and print it
	result := int64(math.Ceil(float64(N) / float64(min))) + 4
	p(result)
}

// Overloaded print methods to handle different data types
func p(ans interface{}) {
	fmt.Println(ans)
}

// <END-OF-CODE>
