package main

import (
	"fmt"
	"math/big"
)

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

// Function to calculate the least common multiple (LCM) of two numbers
func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func main() {
	const MOD = 1000000007 // Define a constant MOD for modulo operations

	var N int
	fmt.Scan(&N) // Read the number of elements in the list A
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Read the list A as integers
	}

	_lcm := 1 // Initialize _lcm to 1
	for _, a := range A {
		_lcm = lcm(_lcm, a) // Update _lcm to be the LCM of _lcm and the current element
	}

	// Calculate the sum of modular inverses of each element in A modulo MOD
	sumInv := 0
	for _, s := range A {
		inv := new(big.Int).ModInverse(big.NewInt(int64(s)), big.NewInt(MOD))
		sumInv = (sumInv + int(inv.Int64())) % MOD
	}

	// Calculate ans as _lcm multiplied by the sum of modular inverses of each element in A modulo MOD
	ans := (_lcm * sumInv) % MOD

	fmt.Println(ans) // Print the result, ensuring it is within the modulo range
}

// <END-OF-CODE>
