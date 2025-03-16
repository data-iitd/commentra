package main

import (
	"fmt"
)

const MOD = 1000000007

// Function to calculate x^n % MOD using bitwise operations
func modPow(x, n int) int {
	ans := 1
	for n > 0 {
		if n&1 == 1 { // Check if the least significant bit is 1
			ans = ans * x % MOD // Update ans if the bit is set
		}
		x = x * x % MOD // Square x and take modulo MOD
		n >>= 1 // Shift n right by 1 bit (divide by 2)
	}
	return ans
}

// Function to calculate combination C(n, r) % MOD
func combS(n, r int) int {
	tmpN := 1
	tmpD := 1
	ans := 0
	for i := 1; i <= r; i++ {
		tmpN = (tmpN * (n + 1 - i)) % MOD // Compute the numerator
		tmpD = (tmpD * i) % MOD // Compute the denominator
		ans = tmpN * modPow(tmpD, MOD-2) % MOD // Compute the combination
	}
	return ans
}

func main() {
	var n, a, b int
	var ans int

	fmt.Scan(&n, &a, &b) // Read input values for n, a, and b
	ans = modPow(2, n) // Calculate 2^n % MOD
	ans-- // Subtract 1 from ans
	tmpNd := combS(n, a) // Calculate C(n, a) % MOD
	ans = (ans - tmpNd + MOD) % MOD // Subtract the combination from ans
	ans = (ans - combS(n, b) + MOD) % MOD // Subtract the combination from ans

	fmt.Println(ans) // Output the final result
}

