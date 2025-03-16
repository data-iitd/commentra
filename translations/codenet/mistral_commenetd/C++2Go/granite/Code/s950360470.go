
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 1000000007 // Modulus value

// Helper functions
// a^n
func pow(a, n int) int {
	res := 1 // Initialize result
	for n > 0 { // While n is greater than 0
		if n&1 == 1 { // If n is odd, multiply result with base
			res *= a
		}
		a *= a // Square the base
		n >>= 1 // Divide n by 2
	}
	return res // Return the final result
}

// a^n % mod
func mod_pow(a, n, mod int) int {
	res := 1 // Initialize result
	for n > 0 { // While n is greater than 0
		if n&1 == 1 { // If n is odd, multiply result with base and take modulo
			res = (res * a) % mod
		}
		a = (a * a) % mod // Square the base and take modulo
		n >>= 1 // Divide n by 2
	}
	return res // Return the final result
}

// a^(-1) % mod (only if : a % p!= 0)
func mod_inv(a, mod int) int {
	return mod_pow(a, mod-2, mod) // Calculate the modular inverse of 'a'
}

// nCk % mod
func mod_nCk(n, k, mod int) int {
	if n == 0 || k == 0 { // Base case: nC0 = kC0 = 1
		return 1
	}

	p := 1 // Initialize p
	for i := n - k + 1; i <= n; i++ { // Calculate p = nC(n-k+1)
		p = (p * i) % mod
	}

	q := 1 // Initialize q
	for i := 2; i <= k; i++ { // Calculate q = k!
		q = (q * i) % mod
	}

	q = mod_inv(q, mod) // Calculate q^(-1) modulo'mod'
	return (p * q) % mod // Return the final result: nCk = p * q
}

func main() {
	reader := bufio.NewReader(os.Stdin) // Create a new bufio.Reader to read from the standard input

	fmt.Print("Enter the value of n: ") // Prompt the user to enter the value of n
	n, _ := strconv.Atoi(reader.ReadLine()) // Read the input value for n from the standard input

	fmt.Print("Enter the value of k: ") // Prompt the user to enter the value of k
	k, _ := strconv.Atoi(reader.ReadLine()) // Read the input value for k from the standard input

	fmt.Println(mod_nCk(k, n, MOD)) // Print the result of nCk modulo 'MOD'
}

Translate the above Go code to C++ and end with comment "