package main

import (
	"fmt"
	"math/big"
)

func main() {
	var N int
	fmt.Scan(&N) // Reading the number of integers N from the standard input
	A := make([]int, N) // Creating an integer slice A of size N

	// Using a for loop to read each integer in the slice A from the standard input
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	lcm := big.NewInt(1) // Initializing lcm as 1

	// Using a for loop to calculate the least common multiple (lcm) of all integers in slice A
	for _, ai := range A {
		a := big.NewInt(int64(ai)) // Converting integer ai to big.Int a
		lcm.Mul(lcm.Div(lcm, gcd(lcm, a)), a) // Calculating lcm using division and multiplication
	}

	mod := int64(1000000007) // Setting the modulus value
	modLcm := new(big.Int).Mod(lcm, big.NewInt(mod)).Int64() // Calculating the remainder of lcm modulo mod

	ans := int64(0) // Initializing answer variable as 0

	// Using a for loop to calculate the answer using modular arithmetic
	for _, ai := range A {
		ans = (ans + modDiv(modLcm, int64(ai), mod)) % mod
	}

	// Printing the answer to the standard output stream
	fmt.Println(ans)
}

// A private function modDiv is used to perform modular division
func modDiv(a, b, mod int64) int64 {
	return (a % mod) * modInv(b, mod) % mod
}

// A private function modInv is used to calculate the modular inverse of a number
func modInv(x, mod int64) int64 {
	return modPow(x, mod-2, mod)
}

// A private function modPow is used to calculate the power of a number using modular arithmetic
func modPow(b, e, mod int64) int64 {
	ans := int64(1)
	x := b % mod
	for y := e; y != 0; y >>= 1 {
		if y&1 == 1 {
			ans = (ans * x) % mod
		}
		x = (x * x) % mod
	}
	return ans
}

// A private function gcd is used to calculate the greatest common divisor
func gcd(a, b *big.Int) *big.Int {
	return new(big.Int).GCD(nil, nil, a, b)
}
