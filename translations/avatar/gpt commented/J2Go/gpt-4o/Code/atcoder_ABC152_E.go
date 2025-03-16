package main

import (
	"fmt"
	"math/big"
)

func main() {
	// Create a scanner to read input from the console
	var N int
	fmt.Scan(&N)

	// Initialize a slice A to hold N integers
	A := make([]int, N)

	// Read N integers into the slice A
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Initialize BigInt to calculate the least common multiple (LCM)
	lcm := big.NewInt(1)

	// Calculate the LCM of all elements in the slice A
	for _, ai := range A {
		a := big.NewInt(int64(ai))
		lcm = lcm.Div(lcm, gcd(lcm, a)).Mul(lcm, a)
	}

	// Define the modulus value
	mod := int64(1000000007)

	// Calculate the LCM modulo mod
	modLcm := new(big.Int).Mod(lcm, big.NewInt(mod)).Int64()

	// Initialize the answer variable to accumulate results
	ans := int64(0)

	// Calculate the sum of modDiv for each element in A
	for _, ai := range A {
		ans = (ans + modDiv(modLcm, int64(ai), mod)) % mod
	}

	// Print the final result
	fmt.Println(ans)
}

// Function to perform modular division
func modDiv(a, b, mod int64) int64 {
	return (a % mod) * modInv(b, mod) % mod
}

// Function to compute modular inverse using Fermat's Little Theorem
func modInv(x, mod int64) int64 {
	return modPow(x, mod-2, mod)
}

// Function to perform modular exponentiation
func modPow(b, e, mod int64) int64 {
	ans := int64(1)
	x := b % mod

	// Loop to calculate b^e % mod using exponentiation by squaring
	for y := e; y != 0; y >>= 1 {
		if y&1 == 1 {
			ans = (ans * x) % mod
		}
		x = (x * x) % mod
	}

	// Return the final result of b^e % mod
	return ans
}

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b *big.Int) *big.Int {
	if b.Cmp(big.NewInt(0)) == 0 {
		return a
	}
	return gcd(b, new(big.Int).Mod(a, b))
}
