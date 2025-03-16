package main

import (
	"fmt"
	"math"
)

const (
	INF = math.MaxFloat64
	MOD = 1e9 + 7
)

func min(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	var q, h, s, d, n int
	fmt.Scan(&q, &h, &s, &d)
	fmt.Scan(&n)

	// Calculate the best price for 1 liter of drink
	best1L := min(float64(q*4), min(float64(h*2), float64(s)))

	// Calculate the best price for 2 liters of drink
	best2L := min(float64(d), best1L*2)

	// Calculate and print the total cost based on whether n is even or odd
	if n%2 == 0 {
		fmt.Println(int(best2L * float64(n/2))) // Total cost for even number of drinks
	} else {
		fmt.Println(int(best2L*float64(n/2) + best1L)) // Total cost for odd number of drinks
	}
}

// <END-OF-CODE>
