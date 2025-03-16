package main

import (
	"fmt"
)

// Function declaration for the you function
func you(x, y int) int {
	// Infinite loop to apply the Euclidean algorithm
	for {
		z := x % y
		x = y
		y = z
		if y <= 0 {
			break
		}
	}
	return x
}

func main() {
	var x, y, z int
	fmt.Scan(&x, &y)
	if x >= y {
		z = you(x, y)
	} else {
		z = you(y, x)
	}
	fmt.Println(z)
}

