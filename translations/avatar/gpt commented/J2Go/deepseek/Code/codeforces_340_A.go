package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a Scanner object to read input from the user
	var s = new(Scanner)
	
	// Read four long integer inputs from the user
	var x, y, a, b int64
	fmt.Scan(&x, &y, &a, &b)
	
	// Initialize variables for calculations
	var j int64 = 2
	var ans bool = true
	
	// Determine the maximum of x and y
	var c int64 = int64(math.Max(float64(x), float64(y)))
	
	// Check if the maximum value exceeds the upper bound b
	if c > b {
		fmt.Println("0")
		ans = false
	}
	
	// Loop to find the least common multiple (LCM) of x and y
	for c % int64(math.Min(float64(x), float64(y))) != 0 && ans {
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
			fmt.Println("0")
			ans = false
			break
		}
	}
	
	// If a valid multiple was found within the bounds
	if ans {
		var count int64 = 0
		// Find the first multiple of c within the range [a, b]
		for i := a; i <= b; i++ {
			if i % c == 0 {
				break
			}
		}
		
		// Check if a valid multiple was found within the range
		if i != b + 1 {
			// Calculate the number of multiples of c in the range [a, b]
			fmt.Println(((b - i) / c) + 1)
		} else {
			fmt.Println("0")
		}
	}
}
