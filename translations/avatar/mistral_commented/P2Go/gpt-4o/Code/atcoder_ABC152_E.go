package main

import (
	"fmt"
	"math/big"
)

// Function to calculate the greatest common divisor (GCD) of two numbers.
func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

// Function to calculate the least common multiple (LCM) of two numbers.
func lcm(a, b int) int {
	return a * (b / gcd(a, b))
}

func main() {
	const MOD = 1000000007

	// Reading the input N.
	var N int
	fmt.Scan(&N)

	// Reading the list A of N integers.
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Initializing the variable _lcm to 1.
	_lcm := 1

	// Iterating through each number a in the list A and updating the value of _lcm using the lcm function.
	for _, a := range A {
		_lcm = lcm(_lcm, a)
	}

	// Calculating the answer ans using the formula _lcm * sum ( [ pow ( s , MOD - 2 , MOD ) for s in A ] ) % MOD.
	ans := big.NewInt(int64(_lcm))
	sum := big.NewInt(0)

	for _, s := range A {
		inv := new(big.Int).Exp(big.NewInt(int64(s)), big.NewInt(int64(MOD-2)), big.NewInt(int64(MOD)))
		sum.Add(sum, inv)
		sum.Mod(sum, big.NewInt(int64(MOD)))
	}

	ans.Mul(ans, sum)
	ans.Mod(ans, big.NewInt(int64(MOD)))

	// Printing the final answer.
	fmt.Println(ans)
}

// <END-OF-CODE>
