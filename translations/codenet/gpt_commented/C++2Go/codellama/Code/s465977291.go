package main

import (
	"fmt"
	"math"
)

func main() {
	// Declare variables for the number of items (n) and the distance (d)
	var n, d int

	// Read input values for n and d from the user
	fmt.Scan(&n, &d)

	// Calculate the effective range of coverage, which is (d*2 + 1)
	a := d*2 + 1

	// Calculate and output the minimum number of groups needed to cover 'n' items
	// This is done by dividing 'n' by the coverage 'a' and rounding up to the nearest whole number
	fmt.Println(math.Ceil(float64(n) / a))
}

