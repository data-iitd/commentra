package main

import (
	"fmt"
	"math"
)

func main() {
	var q int
	fmt.Scan(&q)

	for i := 0; i < q; i++ {
		var n int
		fmt.Scan(&n)

		// Calculating the highest power of 2 less than or equal to n
		x := int(math.Log2(float64(n))) + 1

		// Calculating the final result using the derived formula
		s := -1 * int(math.Pow(2, float64(x))) + 2 + (int(n) * (int(n) + 1) / 2) - int(math.Pow(2, float64(x)))

		// Printing the result for the current test case
		fmt.Println(s)
	}
}

