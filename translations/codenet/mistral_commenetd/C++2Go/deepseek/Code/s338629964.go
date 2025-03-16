package main

import (
	"fmt"
	"math"
)

const MOD2 = 1000000007
const MOD = 998244353
const INF = (1 << 30) - 1
const LINF = 1 << 60
const EPS = 1e-10

type Int = int64

var fact = make([]Int, 1100000)
var revfact = make([]Int, 1100000)
var rev = make([]Int, 1100000)

func init() {
	m := MOD
	fact[0] = 1
	revfact[0] = 1
	rev[0] = 0
	rev[1] = 1
	for i := 1; i < 1100000; i++ {
		fact[i] = fact[i-1] * Int(i) % m
		if i > 1 {
			rev[i] = MOD / Int(i) * (MOD - rev[MOD % Int(i)]) % MOD
		}
		revfact[i] = revfact[i-1] * rev[i] % MOD
	}
}

func nCk(n, k Int) Int {
	if n < k {
		return 0
	}
	if comb[n][k] != 0 {
		return comb[n][k]
	}
	var res Int = fact[n] * revfact[n-k] % MOD * revfact[k] % MOD
	comb[n][k] = res
	return res
}

func mod_pow(x, a, m Int) Int {
	if a == 0 {
		return 1
	}
	res := mod_pow(x, a / 2, m)
	res = res * res % m
	if a % 2 != 0 {
		res *= x
	}
	return res % m
}

func inv(x, m Int) Int {
	return mod_pow(x, m-2, m)
}

func main() {
	var aall, ball Int
	var n, ans int
	var a = make([]Int, 440)
	var b = make([]Int, 440)

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i], &b[i])
		aall += a[i]
		ball += b[i]
	}

	var comb = make([][]Int, 1100)
	for i := range comb {
		comb[i] = make([]Int, 1100)
	}

	var dp = make([][][][]Int, 2)
	for i := range dp {
		dp[i] = make([][][]Int, aall+1)
		for j := range dp[i] {
			dp[i][j] = make([][]Int, 2)
			for k := range dp[i][j] {
				dp[i][j][k] = make([]Int, 2)
			}
		}
	}

	dp[0][0][0][0] = 1
	for i := 1; i <= n; i++ {
		id := i % 2
		for asum := aall; asum >= 0; asum-- {
			for cnt := 0; cnt <= ball; cnt++ {
				for p := 0; p < 2; p++ {
					if asum-a[i-1] < 0 {
						continue
					}
					Int pw := 1
					for use := 0; use < b[i-1]; use++ {
						if cnt-use >= 0 {
							Int tmp := nCk(cnt, use) % MOD * pw % MOD
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

	for asum := 0; asum <= aall; asum++ {
		rev_asum_pow := 1
		for cnt := 0; cnt <= ball; cnt++ {
			rev_asum_pow = rev_asum_pow * rev[asum] % MOD
			for p := 0; p < 2; p++ {
				Int x := dp[asum][cnt][p][1] * rev_asum_pow % MOD * (cnt+1) % MOD * aall % MOD * rev[asum] % MOD
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
