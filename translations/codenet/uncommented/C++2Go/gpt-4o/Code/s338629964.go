package main

import (
	"fmt"
)

const (
	MOD      = 998244353
	MAX_SIZE = 1100000
)

var (
	fact      [MAX_SIZE]int64
	revfact   [MAX_SIZE]int64
	rev       [MAX_SIZE]int64
	comb      [1100][1100]int64
	aall, ball int64
	n          int
	ans        int64
	a          [440]int64
	b          [440]int64
	dp         [440][440][2][2]int64
)

func init() {
	m := MOD
	fact[0] = 1
	revfact[0] = 1
	rev[0] = 0
	rev[1] = 1
	for i := 1; i < MAX_SIZE; i++ {
		fact[i] = fact[i-1] * int64(i) % m
		if i > 1 {
			rev[i] = MOD/int64(i) * (MOD-rev[MOD%int64(i)]) % MOD
		}
		revfact[i] = revfact[i-1] * rev[i] % MOD
	}
}

func nCk(n, k int64) int64 {
	if n < k {
		return 0
	}
	if comb[n][k] != 0 {
		return comb[n][k]
	}
	res := fact[n] * revfact[n-k] % MOD * revfact[k] % MOD
	comb[n][k] = res
	return res
}

func modPow(x, a int64, m int64) int64 {
	if a == 0 {
		return 1
	}
	res := modPow(x, a/2, m)
	res = res * res % m
	if a%2 != 0 {
		res = res * x % m
	}
	return res
}

func inv(x int64, m int64) int64 {
	return modPow(x, m-2, m)
}

func main() {
	init()
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i], &b[i])
		aall += a[i]
		ball += b[i]
	}

	dp[0][0][0][0] = 1
	for i := 1; i <= n; i++ {
		id := i % 2
		for asum := aall; asum >= 0; asum-- {
			for cnt := int64(0); cnt <= ball; cnt++ {
				for p := 0; p < 2; p++ {
					if asum-a[i-1] < 0 {
						continue
					}
					pw := int64(1)
					for use := int64(0); use < b[i-1]; use++ {
						if cnt-use >= 0 {
							tmp := nCk(cnt, use) % MOD * pw % MOD
							dp[asum][cnt][p][0] += dp[asum-a[i-1]][cnt-use][p^1][0] * tmp % MOD
							dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-use][p^1][1] * tmp % MOD
						} else {
							break
						}
						pw = pw * a[i-1] % MOD
					}
					if cnt-b[i-1]+1 >= 0 {
						dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-b[i-1]+1][p^1][0] * nCk(cnt, b[i-1]-1) % MOD * pw % MOD
					}
					dp[asum][cnt][p][0] %= MOD
					dp[asum][cnt][p][1] %= MOD
				}
			}
		}
	}

	for asum := int64(0); asum <= aall; asum++ {
		revAsumPow := int64(1)
		for cnt := int64(0); cnt <= ball; cnt++ {
			revAsumPow = revAsumPow * rev[asum] % MOD
			for p := 0; p < 2; p++ {
				x := dp[asum][cnt][p][1] * revAsumPow % MOD * (cnt + 1) % MOD * aall % MOD * rev[asum] % MOD
				if p == 1 {
					ans += x
				} else {
					ans -= x
				}
				ans %= MOD
			}
		}
	}
	if ans < 0 {
		ans += MOD
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
