package main

import (
	"fmt"
)

const MOD = 1000000007

func modPow(x, n int64) int64 {
	ans := int64(1)
	for n > 0 {
		if n&1 == 1 {
			ans = ans * x % MOD
		}
		x = x * x % MOD
		n >>= 1
	}
	return ans
}

func combS(n, r int64) int64 {
	tmpN := int64(1)
	tmpD := int64(1)
	var ans int64
	for i := int64(1); i <= r; i++ {
		tmpN = (tmpN * (n + 1 - i)) % MOD
		tmpD = (tmpD * i) % MOD
		ans = tmpN * modPow(tmpD, MOD-2) % MOD
	}
	return ans
}

func main() {
	var n, a, b int64
	var ans int64 = 1

	fmt.Scan(&n, &a, &b)

	ans = modPow(2, n)
	ans--

	tmpND := combS(n, a)
	ans = (ans - tmpND + MOD) % MOD

	tmpND = combS(n, b)
	ans = (ans - tmpND + MOD) % MOD

	fmt.Println(ans)
}

// <END-OF-CODE>
