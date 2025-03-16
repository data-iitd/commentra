package main

import (
	"fmt"
)

const MOD = 1000000007

// Function to compute (x^n) % MOD using modular exponentiation
func modPow(x, n int) int {
	ans := 1
	for n > 0 {
		if n&1 == 1 {
			ans = ans * x % MOD
		}
		x = x * x % MOD
		n >>= 1
	}
	return ans
}

// Function to compute combination C(n, r) % MOD using modular arithmetic
func combS(n, r int) int {
	tmpN := 1
	tmpD := 1
	ans := 0
	for i := 1; i <= r; i++ {
		tmpN = (tmpN * (n + 1 - i)) % MOD
		tmpD = (tmpD * i) % MOD
		ans = tmpN * modPow(tmpD, MOD-2) % MOD
	}
	return ans
}

func main() {
	var n int
	var a int
	var b int
	var ans int = 1

	// Input the values of n, a, and b
	fmt.Scan(&n, &a, &b)

	// Calculate 2^n - 1 (total subsets excluding the empty set)
	ans = modPow(2, n)
	ans--

	var tmpNd int

	// Calculate C(n, a) and subtract from ans
	tmpNd = combS(n, a)
	ans = (ans - tmpNd) % MOD
	for ans < 0 {
		ans += MOD
	}

	// Calculate C(n, b) and subtract from ans
	tmpNd = combS(n, b)
	ans = (ans - tmpNd) % MOD
	for ans < 0 {
		ans += MOD
	}

	// Output the final result
	fmt.Println(ans)
}

