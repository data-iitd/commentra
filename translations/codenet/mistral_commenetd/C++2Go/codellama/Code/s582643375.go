
package main

import (
	"fmt"
	"math"
)

const mod = 1e9 + 7 // Modulus value for modular arithmetic
const NMAX = 1000010 // Maximum size of the arrays

var fac [NMAX]int // Arrays for storing factorials, their inverses, and fast inverse
var finv [NMAX]int
var inv [NMAX]int

// Initialize the arrays with factorials, inverses, and fast inverse values
func init() {
	fac[0], fac[1] = 1, 1 // Base cases
	finv[0], finv[1] = 1, 1 // Base cases
	inv[1] = 1 // Base case
	for i := 2; i < NMAX; i++ { // Iterate from 2 to NMAX-1
		fac[i] = fac[i-1] * i % mod // Multiply the current number with the previous factorial
		inv[i] = mod - inv[mod%i] * (mod/i) % mod // Calculate the inverse of the current number using extended Euclidean algorithm
		finv[i] = finv[i-1] * inv[i] % mod // Multiply the previous fast inverse with the current inverse to get the fast inverse
	}
}

// Calculate the binomial coefficient C(n, k) using the precomputed values
func C(n, k int) int {
	if n < k { // Return 0 if n is less than k
		return 0
	}
	if n < 0 || k < 0 { // Return 0 if n or k is negative
		return 0
	}
	return fac[n] * (finv[k] * finv[n-k] % mod) % mod // Multiply the factorial of n with the product of the fast inverse of k and the fast inverse of n-k, then take the modulo
}

func main() {
	init() // Initialize the arrays
	var X, Y int // Read input values for X and Y
	fmt.Scan(&X, &Y)
	if (X+Y)%3 != 0 { // Check if the sum of X and Y is not divisible by 3
		fmt.Println(0) // If not, print 0 and exit
		return
	}
	n := (X + Y) / 3 + 1 // Calculate the value of n = (X+Y)/3 + 1
	k := 2*(n-1) - Y + 1 // Calculate the value of k = 2*(n-1) - Y + 1
	fmt.Println(C(n-1, k-1)) // Print the binomial coefficient C(n-1, k-1)
}

