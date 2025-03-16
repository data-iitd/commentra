package main

import (
	"fmt"
	"math"
)

func main() {
	// Read input values from the standard input
	var a, b, c, k int
	fmt.Scan(&a, &b, &c, &k)

	// Check if the sum of A and B is greater than or equal to K
	if a+b >= k {
		// If true, print the minimum value between A and K
		fmt.Println(int(math.Min(float64(a), float64(k))))
	} else {
		// If false, calculate the difference between K and the sum of A and B,
		// and subtract it from A to get the required value
		fmt.Println(a - (k - (a + b)))
	}
}

