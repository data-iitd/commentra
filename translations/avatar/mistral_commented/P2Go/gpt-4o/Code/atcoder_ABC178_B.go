package main

import (
	"fmt"
	"math"
)

const (
	inf = 1e20
	mod = 1e9 + 7
)

func main() {
	// Read input values
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)

	// Calculate the maximum product of pairs of numbers
	result := int(math.Max(float64(a*c), math.Max(float64(b*d), math.Max(float64(a*d), float64(b*c)))))

	// Print the result
	fmt.Println(result)
}

// <END-OF-CODE>
