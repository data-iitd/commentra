package main

import (
	"fmt"
	"math/big"
)

// Define K and N as integers read from the standard input
var K, N int

// Define a helper function to print arguments with a space between them
func dprint(x ...interface{}) {
	fmt.Println(x...)
}

// Define a function to compute the number of combinations of r items chosen from a set of n items, modulo a given modulus
func cmb(n, r, mod int) *big.Int {
	// Check if r is out of range
	if r < 0 || r > n {
		return big.NewInt(0)
	}
	// Adjust r to be between 0 and n
	if r > n-r {
		r = n - r
	}
	// Compute the combination using the formula
	numerator := big.NewInt(1)
	denominator := big.NewInt(1)
	for i := 1; i <= r; i++ {
		numerator.Mul(numerator, big.NewInt(int64(n-i+1)))
		denominator.Mul(denominator, big.NewInt(int64(i)))
	}
	result := new(big.Int).Div(numerator, denominator)
	return new(big.Int).Mod(result, big.NewInt(int64(mod)))
}

// Set the modulus to 998244353
const mod = 998244353

// Define a constant N for the size of the arrays
const __N = 8000

// Initialize g1 and g2 with the first two elements
var g1 = []*big.Int{big.NewInt(1), big.NewInt(1)}
var g2 = []*big.Int{big.NewInt(1), big.NewInt(1)}

// Initialize inverse with the first two elements and the identity list
var inverse = []int{0, 1}

// Initialize a map to store precomputed factorials and their modular inverses
var fact = map[int]*big.Int{0: big.NewInt(1), 1: big.NewInt(1)}
var invFact = map[int]*big.Int{0: big.NewInt(1), 1: big.NewInt(1)}

// Function to compute the modular inverse
func modInverse(a, mod int) *big.Int {
	if v, ok := invFact[a]; ok {
		return v
	}
	for i := len(invFact); i <= a; i++ {
		fact[i] = new(big.Int).Mul(fact[i-1], big.NewInt(int64(i)))
		fact[i].Mod(fact[i], big.NewInt(int64(mod)))
		invFact[i] = new(big.Int).ModInverse(fact[i], big.NewInt(int64(mod)))
	}
	return invFact[a]
}

// Define a function to compute the value of a combinatorial sum
func kumiawase(p, q int) *big.Int {
	// Compute the combination using the cmb function
	return cmb(p+q-1, q-1, mod)
}

// Define a function to compute the answer for a given value of n
func solve(n int) *big.Int {
	// Check if n is out of range
	if n > K+1 {
		return big.NewInt(0)
	}
	// Initialize the answer as 0
	var ans big.Int
	// Compute the number of pairs (p, q) such that p <= N and q <= K - p
	kumi := (n - 1) / 2
	// Compute the answer using the kumiawase function and the precomputed values
	for p := 0; p <= kumi; p++ {
		if p > N {
			break
		}
		ans.Add(&ans, new(big.Int).Mul(new(big.Int).Exp(big.NewInt(2), big.NewInt(int64(p)), nil), new(big.Int).Mul(cmb(kumi, p, mod), kumiawase(N-p, p+(K-kumi*2-(n%2)))).Mod(&ans, mod)))
		if n%2 == 0 && N-p-1 >= 0 {
			ans.Add(&ans, new(big.Int).Mul(new(big.Int).Exp(big.NewInt(2), big.NewInt(int64(p)), nil), new(big.Int).Mul(cmb(kumi, p, mod), kumiawase(N-p-1, p+(K-kumi*2-(n%2)))).Mod(&ans, mod)))
		}
	}
	// Return the answer
	return &ans
}

// Initialize an empty list to store the answers
var ans []*big.Int

// Compute the answers for all integers from 2 to 2K+1
for i := 2; i <= 2*K; i++ {
	// Compute the answer for the current integer using the solve function
	tmp := solve(i).Mod(&ans, mod)
	// Store the answer in the ans list
	ans = append(ans, tmp)
	// Print the answer
	fmt.Println(tmp)
}

// Print the answers for the negative integers by reprinting the results from the ans list
for i := 2; i <= 2*K; i++ {
	if i <= K+1 {
		fmt.Println(ans[i-K])
	} else {
		fmt.Println(ans[-i+K])
	}
}

