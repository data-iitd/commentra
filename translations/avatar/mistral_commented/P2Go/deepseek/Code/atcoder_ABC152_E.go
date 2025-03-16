package main

import (
	"fmt"
	"math/big"
)

// Function to calculate the greatest common divisor (GCD) of two numbers.
func gcd(a, b *big.Int) *big.Int {
	return new(big.Int).GCD(nil, nil, a, b)
}

// Function to calculate the least common multiple (LCM) of two numbers.
func lcm(a, b *big.Int) *big.Int {
	// Calculate the greatest common divisor of a and b using the gcd function.
	g := new(big.Int).GCD(nil, nil, a, b)
	// Return the product of a and b divided by their greatest common divisor.
	return new(big.Int).Mul(a, b).Div(new(big.Int).Div(new(big.Int).Mul(a, b), g), g)
}

func main() {
	// Setting the value of MOD to 10^9 + 7.
	const MOD = "1000000007"

	// Reading the input N and storing the list A of N integers.
	var N int
	fmt.Scan(&N)
	A := make([]*big.Int, N)
	for i := 0; i < N; i++ {
		var x int
		fmt.Scan(&x)
		A[i] = big.NewInt(int64(x))
	}

	// Initializing the variable _lcm to 1.
	_lcm := big.NewInt(1)

	// Iterating through each number a in the list A and updating the value of _lcm using the lcm function.
	for _, a := range A {
		// Update the value of _lcm using the lcm function.
		_lcm = lcm(_lcm, a)
	}

	// Calculating the sum of the modular inverses of each element in A.
	sum := big.NewInt(0)
	for _, s := range A {
		inv := new(big.Int).Exp(s, big.NewInt(int64(MOD-2)), nil)
		sum.Add(sum, inv).Mod(sum, big.NewInt(int64(MOD)))
	}

	// Calculating the answer ans using the formula _lcm * sum % MOD.
	ans := new(big.Int).Mul(_lcm, sum).Mod(ans, big.NewInt(int64(MOD)))

	// Printing the final answer.
	fmt.Println(ans)
}
