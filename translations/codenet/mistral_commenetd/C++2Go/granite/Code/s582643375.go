

package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 100000007 // Modulus value for modular arithmetic
const NMAX = 1000010 // Maximum size of the arrays

var fac, finv, inv [NMAX]int // Arrays for storing factorials, their inverses, and fast inverse

// Initialize the arrays with factorials, inverses, and fast inverse values
func init() {
	fac[0] = fac[1] = 1 // Base cases
	finv[0] = finv[1] = 1 // Base cases
	inv[1] = 1 // Base case
	for i := 2; i < NMAX; i++ { // Iterate from 2 to NMAX-1
		fac[i] = fac[i-1] * i % MOD // Multiply the current number with the previous factorial
		inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD // Calculate the inverse of the current number using extended Euclidean algorithm
		finv[i] = finv[i-1] * inv[i] % MOD // Multiply the previous fast inverse with the current inverse to get the fast inverse
	}
}

// Calculate the binomial coefficient C(n, k) using the precomputed values
func C(n, k int) int {
	if n < k {
		return 0 // Return 0 if n is less than k
	}
	if n < 0 || k < 0 {
		return 0 // Return 0 if n or k is negative
	}
	return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD // Multiply the factorial of n with the product of the fast inverse of k and the fast inverse of n-k, then take the modulo
}

func main() {
	init() // Initialize the arrays
	data := bufio.NewScanner(os.Stdin) // Create a scanner to read input from the standard input
	data.Split(bufio.ScanWords) // Split the input into words
	data.Scan() // Read the first word
	X, _ := fmt.Sscanf(data.Text(), "%d", &X) // Convert the first word to an integer and store it in X
	data.Scan() // Read the second word
	Y, _ := fmt.Sscanf(data.Text(), "%d", &Y) // Convert the second word to an integer and store it in Y
	if (X+Y)%3!= 0 { // Check if the sum of X and Y is not divisible by 3
		fmt.Println(0) // If not, print 0 and exit
		return // Exit the program
	}
	n := (X + Y) / 3 + 1 // Calculate the value of n = (X+Y)/3 + 1
	k := 2*(n-1) - Y + 1 // Calculate the value of k = 2*(n-1) - Y + 1
	fmt.Println(C(n-1, k-1)) // Print the binomial coefficient C(n-1, k-1)
}

