package main

import (
	"fmt"
	"math"
)

func main() {
	// Take an integer input x
	var x int
	fmt.Scan(&x)

	// Calculate the number of distinct cyclic permutations of a string of length x
	fmt.Println(360 / gcd(360, x))
}

// gcd function to calculate the greatest common divisor
func gcd(a, b int) int {
	return int(math.Gcd(float64(a), float64(b)))
}

// <END-OF-CODE>
