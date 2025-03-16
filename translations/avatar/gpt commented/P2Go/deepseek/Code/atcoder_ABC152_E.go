package main

import (
	"fmt"
	"math/big"
)

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b *big.Int) *big.Int {
	return new(big.Int).GCD(nil, nil, a, b)
}

// Function to calculate the least common multiple (LCM)
func lcm(a, b *big.Int) *big.Int {
	// Calculate the least common multiple (LCM) of two numbers a and b
	return new(big.Int).Mul(a, new(big.Int).Div(b, gcd(a, b)))
}

const MOD = 1000000007 // Define a constant MOD for modular arithmetic

func main() {
	var N int
	fmt.Scan(&N) // Read the number of elements from user input

	var A []int
	for i := 0; i < N; i++ {
		var a int
		fmt.Scan(&a)
		A = append(A, a)
	}

	_lcm := big.NewInt(1) // Initialize the variable to store the LCM of the list
	for _, a := range A {
		// Update the LCM by calculating the LCM of the current LCM and the next element
		_lcm = lcm(_lcm, big.NewInt(int64(a)))
	}

	// Calculate the final answer using the LCM and the modular inverses of the elements in A
	sum := big.NewInt(0)
	for _, s := range A {
		inv := new(big.Int).ModInverse(big.NewInt(int64(s)), big.NewInt(MOD))
		sum.Add(sum, inv)
	}

	ans := new(big.Int).Mul(_lcm, sum)
	ans.Mod(ans, big.NewInt(MOD))

	// Print the result, ensuring it is within the bounds of MOD
	fmt.Println(ans)
}
