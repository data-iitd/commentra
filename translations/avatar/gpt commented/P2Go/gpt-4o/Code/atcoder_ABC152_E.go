package main

import (
	"fmt"
	"math/big"
)

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int64) int64 {
	return a * b / gcd(a, b)
}

func main() {
	const MOD = 1000000007 // Define a constant MOD for modular arithmetic
	var N int64
	fmt.Scan(&N) // Read the number of elements from user input

	A := make([]int64, N)
	for i := int64(0); i < N; i++ {
		fmt.Scan(&A[i]) // Read a list of integers from user input
	}

	_lcm := int64(1) // Initialize the variable to store the LCM of the list
	for _, a := range A {
		_lcm = lcm(_lcm, a) // Update the LCM
	}

	// Calculate the final answer using the LCM and the modular inverses of the elements in A
	ans := new(big.Int).SetInt64(_lcm) // Start with the LCM
	sum := int64(0)

	for _, s := range A {
		inv := new(big.Int).ModInverse(big.NewInt(s), big.NewInt(MOD)) // Calculate modular inverse
		sum = (sum + inv.Int64()) % MOD
	}

	ans.Mul(ans, big.NewInt(sum)) // Multiply LCM with the sum of inverses
	ans.Mod(ans, big.NewInt(MOD))  // Take modulo

	// Print the result, ensuring it is within the bounds of MOD
	fmt.Println(ans.Int64())
}

// <END-OF-CODE>
