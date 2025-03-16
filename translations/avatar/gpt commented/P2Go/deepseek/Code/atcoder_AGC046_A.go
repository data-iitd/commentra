package main

import (
	"fmt"
	"math"
)

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b int) int {
	return int(math.GCD(float64(a), float64(b)))
}

func main() {
	// Take an integer input from the user
	var x int
	fmt.Scan(&x)

	// Calculate and print the number of equal parts in a full circle (360 degrees)
	// that can be formed with the given angle x using the gcd
	fmt.Println(360 / gcd(360, x))
}
