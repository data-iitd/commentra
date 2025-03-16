
package main

import (
	"fmt"
)

// Define a constant value for MOD
const MOD = 1000000007

// Define a function to calculate x raised to the power n modulo MOD
func mod_pow(x, n int64) int64 {
	ans := int64(1)
	for n > 0 {
		if n&1 == 1 {
			ans = (ans * x) % MOD
		}
		x = (x * x) % MOD
		n >>= 1
	}
	return ans
}

// Define a function to calculate nCr (n choose r) using combinatorics formula
func comb_s(n, r int64) int64 {
	tmp_n := int64(1)
	tmp_d := int64(1)
	ans := int64(0)
	for i := int64(1); i <= r; i++ {
		tmp_n = (tmp_n * (n + 1 - i)) % MOD
		tmp_d = (tmp_d * i) % MOD
		ans = (tmp_n * mod_pow(tmp_d, MOD-2)) % MOD
	}
	return ans
}

func main() {
	var n, a, b int64
	fmt.Scan(&n, &a, &b)
	ans := mod_pow(2, n)
	ans--
	tmp_nd := comb_s(n, a)
	ans = (ans - tmp_nd) % MOD
	tmp_nd = comb_s(n, b)
	ans = (ans - tmp_nd) % MOD
	for ans < 0 {
		ans += MOD
	}
	fmt.Println(ans)
}

