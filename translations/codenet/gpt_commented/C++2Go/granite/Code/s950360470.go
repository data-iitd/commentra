
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007 // Define a constant for modulo operation (1000000007)

// Function to compute a raised to the power n (a^n)
func pow(a, n int) int {
	res := 1 // Initialize result to 1
	for n > 0 { // Loop until n becomes 0
		if n&1 == 1 { // If n is odd, multiply result by a
			res *= a
		}
		a *= a // Square the base
		n >>= 1 // Divide n by 2
	}
	return res // Return the computed power
}

// Function to compute a raised to the power n modulo mod (a^n % mod)
func mod_pow(a, n, mod int) int {
	res := 1 // Initialize result to 1
	for n > 0 { // Loop until n becomes 0
		if n&1 == 1 { // If n is odd, multiply result by a and take modulo
			res = res * a % mod
		}
		a = a * a % mod // Square the base and take modulo
		n >>= 1 // Divide n by 2
	}
	return res // Return the computed power modulo
}

// Function to compute modular multiplicative inverse of a modulo mod (a^(-1) % mod)
// This function assumes that a is not divisible by mod
func mod_inv(a, mod int) int {
	return mod_pow(a, mod-2, mod) // Use Fermat's Little Theorem to compute inverse
}

// Function to compute n choose k modulo mod (nCk % mod)
func mod_nCk(n, k, mod int) int {
	if n == 0 || k == 0 { // Base case: nC0 = 1
		return 1
	}
	p := 1 // Initialize numerator (p)
	q := 1 // Initialize denominator (q)
	for i := n - k + 1; i <= n; i++ { // Calculate the numerator for nCk
		p = (p * i) % MOD
	}
	for i := 2; i <= k; i++ { // Calculate the denominator for nCk
		q = (q * i) % MOD
	}
	q = mod_inv(q, MOD) // Compute the modular inverse of the denominator
	return (p * q) % MOD // Return the result of nCk modulo
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the value of n:")
	n, _ := reader.ReadString('\n')
	fmt.Println("Enter the value of k:")
	k, _ := reader.ReadString('\n')
	nInt, _ := strconv.Atoi(strings.TrimSpace(n))
	kInt, _ := strconv.Atoi(strings.TrimSpace(k))
	fmt.Println(mod_nCk(kInt, nInt, MOD)) // Compute and print nCk modulo MOD
}

