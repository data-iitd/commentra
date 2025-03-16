package main

import (
	"fmt"
	"math"
)

// Function to calculate the greatest common divisor (GCD) using the Euclidean algorithm
func gcd(a, b int) int {
	for a%b != 0 {
		a, b = b, a%b
	}
	return b
}

// Function to calculate the least common multiple (LCM) using the relationship between GCD and LCM
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	var x, y, a, b int
	fmt.Scan(&x, &y, &a, &b)

	// Calculate the LCM of x and y
	lcmXY := lcm(x, y)

	// Compute the number of integers in the range from a to b that are divisible by lcm and print the result
	result := b/lcmXY - (a-1)/lcmXY
	fmt.Println(result)
}

