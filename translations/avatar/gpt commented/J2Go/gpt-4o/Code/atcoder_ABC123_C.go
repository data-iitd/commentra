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
	var min int64

	// Loop to read five long integers and find the minimum
	for i := 0; i < 5; i++ {
		var num int64
		fmt.Scan(&num)
		if i == 0 {
			min = num
		} else {
			if num < min {
				min = num
			}
		}
	}

	// Calculate the result by dividing N by min, rounding up, and adding 4
	result := int64(math.Ceil(float64(N) / float64(min))) + 4
	p(result)
}

// Overloaded method to print a long result
func p(ans int64) {
	fmt.Println(ans)
}

// Overloaded method to print an int result
func pInt(ans int) {
	fmt.Println(ans)
}

// Overloaded method to print a string result
func pString(ans string) {
	fmt.Println(ans)
}

// Overloaded method to print a double result
func pDouble(ans float64) {
	fmt.Println(ans)
}

// Overloaded method to print an empty line
func pEmpty() {
	fmt.Println()
}

// Note: In Go, function overloading is not supported, so we use different function names for different types.
