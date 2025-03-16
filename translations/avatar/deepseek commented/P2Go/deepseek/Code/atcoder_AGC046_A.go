package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a % b
	}
	return a
}

func main() {
	var x int
	fmt.Scan(&x)
	
	// Calculate the number of distinct cyclic permutations of a string of length x
	result := 360 / gcd(360, x)
	fmt.Println(result)
}

