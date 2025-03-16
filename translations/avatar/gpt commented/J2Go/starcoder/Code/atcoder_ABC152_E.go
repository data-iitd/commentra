package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input from stdin
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements N
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))

	// Initialize an array A to hold N integers
	A := make([]int, N)

	// Read N integers into the array A
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}

	// Initialize BigInteger to calculate the least common multiple (LCM)
	lcm := big.NewInt(1)

	// Calculate the LCM of all elements in the array A
	for _, ai := range A {
		a := big.NewInt(int64(ai))
		lcm.Div(lcm.Div(lcm, a.GCD(lcm, a).Int64()), lcm.Int64())
	}

	// Define the modulus value
	mod := int64(1000000007)

	// Calculate the LCM modulo mod
	modLcm := lcm.Mod(lcm, big.NewInt(mod)).Int64()

	// Initialize the answer variable to accumulate results
	ans := int64(0)

	// Calculate the sum of modDiv for each element in A
	for _, ai := range A {
		ans = (ans + modDiv(modLcm, int64(ai), mod)) % mod
	}

	// Print the final result
	fmt.Println(ans)
}

// Method to perform modular division
func modDiv(a, b, mod int64) int64 {
	return (a % mod) * modInv(b, mod) % mod
}

// Method to compute modular inverse using Fermat's Little Theorem
func modInv(x, mod int64) int64 {
	return modPow(x, mod-2, mod)
}

// Method to perform modular exponentiation
func modPow(b, e, mod int64) int64 {
	ans := int64(1)
	x := b % mod

	// Loop to calculate b^e % mod using exponentiation by squaring
	for y := e; y!= 0; y >>= 1 {
		if y&1 == 1 {
			ans = (ans * x) % mod
		}
		x = (x * x) % mod
	}

	// Return the final result of b^e % mod
	return ans
}

