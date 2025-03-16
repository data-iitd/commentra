package main

import (
	"fmt"
	"math"
)

// Function to compute (x^y) % mod using modular exponentiation
func modPower(x, y, mod int) int {
	res := 1
	x %= mod // Reduce x modulo mod
	if x == 0 {
		return 0 // If x is 0, return 0
	}

	// Loop until y becomes 0
	for y > 0 {
		// If y is odd, multiply x with result
		if y%2 == 1 {
			res = (res * x) % mod
		}
		y >>= 1 // Divide y by 2
		x = (x * x) % mod // Square x
	}
	return res // Return the final result
}

// Main function to execute the program
func main() {
	var a [4]int64 // Array to hold four long integers

	// Read four long integers from input
	for i := 0; i < 4; i++ {
		fmt.Scan(&a[i])
	}

	// Calculate and print the maximum product of pairs from the array
	maxProduct := int64(math.Max(float64(a[0]*a[2]), 
		math.Max(float64(a[1]*a[3]), 
		math.Max(float64(a[0]*a[3]), float64(a[1]*a[2])))))

	fmt.Println(maxProduct)
}

// <END-OF-CODE>
