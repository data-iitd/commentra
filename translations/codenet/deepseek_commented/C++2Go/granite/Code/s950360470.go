
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the value of n:")
	n, _ := reader.ReadString('\n')
	n = n[:len(n)-1] // Remove the trailing newline character
	fmt.Println("Enter the value of k:")
	k, _ := reader.ReadString('\n')
	k = k[:len(k)-1] // Remove the trailing newline character
	nInt, _ := strconv.Atoi(n)
	kInt, _ := strconv.Atoi(k)
	result := mod_nCk(kInt, nInt, 100000007) // Call the mod_nCk function with the given values
	fmt.Println("The result is:", result) // Print the result
}

func pow(a, n int) int {
	res := 1 // Initialize result
	for n > 0 { // Loop until n becomes 0
		if n&1 == 1 { // If n is odd, multiply result by a
			res *= a
		}
		a *= a // Square a
		n >>= 1 // Divide n by 2
	}
	return res // Return the result
}

func mod_pow(a, n, mod int) int {
	res := 1 // Initialize result
	for n > 0 { // Loop until n becomes 0
		if n&1 == 1 { // If n is odd, multiply result by a modulo mod
			res = (res * a) % mod
		}
		a = (a * a) % mod // Square a modulo mod
		n >>= 1 // Divide n by 2
	}
	return res // Return the result
}

func mod_inv(a, mod int) int {
	return mod_pow(a, mod-2, mod) // Use Fermat's little theorem: a^(mod-2) % mod is a^-1 % mod
}

func mod_nCk(n, k, mod int) int {
	if n == 0 || k == 0 { // Base case: nCk is 1 if n or k is 0
		return 1
	}
	p := 1 // Initialize p
	q := 1 // Initialize q
	for i := n - k + 1; i <= n; i++ { // Calculate numerator
		p = (p * i) % mod
	}
	for i := 2; i <= k; i++ { // Calculate denominator
		q = (q * i) % mod
	}
	q = mod_inv(q, mod) // Calculate inverse of denominator
	return (p * q) % mod // Return the result
}

