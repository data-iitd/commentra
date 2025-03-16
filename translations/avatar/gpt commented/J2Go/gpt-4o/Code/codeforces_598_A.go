package main

import (
	"fmt"
	"math"
)

func main() {
	// Reading the number of test cases
	var q int
	fmt.Scan(&q)

	// Looping through each test case
	for q > 0 {
		q--

		// Reading the integer n for the current test case
		var n int
		fmt.Scan(&n)

		// Initializing a variable to store the result
		var s int64 = 0

		// Calculating the highest power of 2 less than or equal to n
		x := int(math.Log2(float64(n))) + 1

		// Calculating the final result using the derived formula
		s = -1*(int64(math.Pow(2, float64(x)))) + 2 + (int64(n)*(int64(n)+1))/2 - int64(math.Pow(2, float64(x)))

		// Printing the result for the current test case
		fmt.Println(s)
	}
}

// <END-OF-CODE>
