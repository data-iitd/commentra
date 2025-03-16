
package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strconv"
)

func main() {
	// Create a new scanner to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of elements N
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())

	// Initialize an array A to hold N integers
	A := make([]int, N)

	// Read N integers into the array A
	for i := 0; i < N; i++ {
		sc.Scan()
		A[i], _ = strconv.Atoi(sc.Text())
	}

	// Initialize a new big.Int to calculate the least common multiple (LCM)
	lcm := big.NewInt(1)

	// Calculate the LCM of all elements in the array A
	for _, ai := range A {
		a := big.NewInt(int64(ai))
		lcm.Div(lcm, lcm.GCD(nil, nil, a, lcm))
		lcm.Mul(lcm, a)
	}

	// Define the modulus value
	mod := big.NewInt(1000000007)

	// Calculate the LCM modulo mod
	modLcm := new(big.Int).Mod(lcm, mod)

	// Initialize the answer variable to accumulate results
	ans := big.NewInt(0)

	// Calculate the sum of modDiv for each element in A
	for _, ai := range A {
		ans.Add(ans, modDiv(modLcm, big.NewInt(int64(ai)), mod))
	}

	// Print the final result
	fmt.Println(ans.Mod(ans, mod))
}

// Method to perform modular division
func modDiv(a, b, mod *big.Int) *big.Int {
	return new(big.Int).Mul(a, modInv(b, mod))
}

// Method to compute modular inverse using Fermat's Little Theorem
func modInv(x, mod *big.Int) *big.Int {
	return modPow(x, mod.Sub(mod, big.NewInt(2)), mod)
}

// Method to perform modular exponentiation
func modPow(b, e, mod *big.Int) *big.Int {
	ans := big.NewInt(1)
	x := new(big.Int).Mod(b, mod)

	// Loop to calculate b^e % mod using exponentiation by squaring
	for y := e; y.Sign() > 0; y.Rsh(y, 1) {
		if y.Bit(0) == 1 {
			ans.Mul(ans, x)
			ans.Mod(ans, mod)
		}
		x.Mul(x, x)
		x.Mod(x, mod)
	}

	// Return the final result of b^e % mod
	return ans
}

// END-OF-CODE