package main

import (
	"fmt"
	"math"
)

func main() {
	var n, d int
	fmt.Scan(&n, &d)

	a := float64(d*2 + 1)
	// Calculate the value of 'a' which is used in the subsequent calculations.
	fmt.Println(int(math.Ceil(float64(n)/a)))
	// Output the ceiling of the division of n by 'a' to the standard output.
}

// <END-OF-CODE>
