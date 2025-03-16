package main

import (
	"fmt"
	"math"
)

func main() {
	// Take an integer input from the user
	var x int
	fmt.Scan(&x)

	// Calculate and print the number of equal parts in a full circle (360 degrees) 
	// that can be formed with the given angle x using the gcd
	gcdValue := gcd(360, x)
	fmt.Println(360 / gcdValue)
}

// Function to calculate the greatest common divisor
func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

// <END-OF-CODE>
