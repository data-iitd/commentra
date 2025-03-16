package main

import (
	"fmt"
	"math/big"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)

	// Read N integers into array A
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Initialize LCM to 1
	lcm := big.NewInt(1)

	// Calculate the LCM of all elements in array A
	for _, ai := range A {
		a := big.NewInt(int64(ai))
		lcm.Div(lcm, lcm.GCD(nil, nil, lcm, a)).Mul(lcm, a)
	}

	// Define the modulo value
	mod := int64(1000000007)

	// Calculate the LCM modulo 10^9 + 7
	modLcm := new(big.Int).Mod(lcm, big.NewInt(mod)).Int64()

	// Initialize the answer to 0
	var ans int64 = 0

	// Calculate the sum of each element in A divided by the LCM, modulo 10^9 + 7
	for _, ai := range A {
		ans = (ans + modDiv(modLcm, int64(ai), mod)) % mod
	}

	// Print the final answer
	fmt.Println(ans)
}

// Function to perform modular division
func modDiv(a, b, mod int64) int64 {
	return (a % mod) * modInv(b, mod) % mod
}

// Function to calculate modular inverse
func modInv(x, mod int64) int64 {
	return modPow(x, mod-2, mod)
}

// Function to perform modular exponentiation
func modPow(b, e, mod int64) int64 {
	var ans int64 = 1
	x := b % mod
	for y := e; y != 0; y >>= 1 {
		if y&1 == 1 {
			ans = (ans * x) % mod
		}
		x = (x * x) % mod
	}
	return ans
}

