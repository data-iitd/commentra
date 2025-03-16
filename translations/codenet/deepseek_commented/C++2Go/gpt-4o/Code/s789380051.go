package main

import (
	"fmt"
)

const MOD = 1000000007

// Function to calculate x^n % MOD using bitwise operations
func modPow(x, n int64) int64 {
	ans := int64(1)
	for n > 0 {
		if n&1 == 1 { // Check if the least significant bit is 1
			ans = (ans * x) % MOD // Update ans if the bit is set
		}
		x = (x * x) % MOD // Square x and take modulo MOD
		n >>= 1          // Shift n right by 1 bit (divide by 2)
	}
	return ans
}

// Function to calculate combination C(n, r) % MOD
func combS(n, r int64) int64 {
	tmpN := int64(1)
	tmpD := int64(1)
	var ans int64
	for i := int64(1); i <= r; i++ {
		tmpN = (tmpN * (n + 1 - i)) % MOD // Compute the numerator
		tmpD = (tmpD * i) % MOD           // Compute the denominator
		ans = (tmpN * modPow(tmpD, MOD-2)) % MOD // Compute the combination
	}
	return ans
}

func main() {
	var n, a, b int64
	var ans int64 = 1

	fmt.Scan(&n, &a, &b) // Read input values for n, a, and b
	ans = modPow(2, n)   // Calculate 2^n % MOD
	ans--                // Subtract 1 from ans
	tmpND := combS(n, a) // Calculate C(n, a) % MOD
	ans = (ans - tmpND + MOD) % MOD // Subtract the combination from ans

	tmpND = combS(n, b) // Calculate C(n, b) % MOD
	ans = (ans - tmpND + MOD) % MOD // Subtract the combination from ans

	fmt.Println(ans) // Output the final result
}

// <END-OF-CODE>
