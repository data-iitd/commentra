package main

import (
	"fmt"
)

const MOD = 1000000007

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
	var n, a, b int
	fmt.Scan(&n, &a, &b)
	ans := modPow(2, n)
	ans--
	tmpNd := combS(n, a)
	ans = (ans - tmpNd) % MOD
	for ans < 0 {
		ans += MOD
	}
	tmpNd = combS(n, b)
	ans = (ans - tmpNd) % MOD
	for ans < 0 {
		ans += MOD
	}
	fmt.Println(ans)
}

