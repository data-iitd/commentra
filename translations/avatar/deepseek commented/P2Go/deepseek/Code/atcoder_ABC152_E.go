package main

import (
	"fmt"
	"math/big"
)

// Function to calculate the greatest common divisor (GCD) using the Euclidean algorithm
func gcd(a, b *big.Int) *big.Int {
	return new(big.Int).GCD(nil, nil, a, b)
}

// Function to calculate the least common multiple (LCM) of two numbers
func lcm(a, b *big.Int) *big.Int {
	g := new(big.Int).GCD(nil, nil, a, b)
	return new(big.Int).Mul(a, b).Div(new(big.Int).Div(new(big.Int).Mul(a, b), g), g)
}

const MOD = 1000000007

func main() {
	var N int
	fmt.Scan(&N) // Read the number of elements in the list A

	A := make([]*big.Int, N)
	for i := 0; i < N; i++ {
		var x int
		fmt.Scan(&x)
		A[i] = big.NewInt(int64(x)) // Read the list A as integers
	}

	_lcm := big.NewInt(1) // Initialize _lcm to 1
	for _, a := range A {
		_lcm = lcm(_lcm, a) // Update _lcm to be the LCM of _lcm and the current element
	}

	// Calculate ans as _lcm multiplied by the sum of modular inverses of each element in A modulo MOD
	sum := big.NewInt(0)
	for _, s := range A {
		inv := new(big.Int).Exp(s, big.NewInt(MOD-2), nil) // Calculate modular inverse
		sum.Add(sum, inv).Mod(sum, big.NewInt(MOD))       // Sum and modulo
	}

	ans := new(big.Int).Mul(_lcm, sum).Mod(ans, big.NewInt(MOD))

	fmt.Println(ans) // Print the result
}
