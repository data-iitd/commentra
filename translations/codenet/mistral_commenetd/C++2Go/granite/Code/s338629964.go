
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD2 = 1000000007
const MOD = 998244353
const INF = (1 << 30) - 1
const LINF = (1 << 60)
const EPS = 1e-10

type Int int

var fact [1100000]Int
var revfact [1100000]Int
var rev [1100000]Int

func init() {
	m := MOD
	fact[0] = 1
	revfact[0] = 1
	rev[0] = 0
	rev[1] = 1
	for i := 1; i < 1100000; i++ {
		fact[i] = fact[i-1] * i % m
		if i > 1 {
			rev[i] = m / i * (m - rev[m%i]) % m
		}
		revfact[i] = revfact[i-1] * rev[i] % m
	}
}

func nCk(n, k Int) Int {
	if n < k {
		return 0
	}
	if comb[n][k]!= 0 {
		return comb[n][k]
	}
	res := comb[n][k]
	res = fact[n] * revfact[n-k] % MOD * revfact[k] % MOD
	return res
}

func mod_pow(x, a Int, m Int) Int {
	if a == 0 {
		return 1
	}
	res := mod_pow(x, a/2, m)
	res = res * res % m
	if a%2 == 1 {
		res *= x
	}
	return res % m
}

func inv(x, m Int) Int {
	return mod_pow(x, m-2, m)
}

func main() {
	var n, ans Int
	var aall, ball Int
	var a, b [440]Int
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var aInt, bInt Int
	scanner.Scan()
	aInt = scanner.Text()[0] - '0'
	n += aInt
	aall += aInt
	scanner.Scan()
	bInt = scanner.Text()[0] - '0'
	n += bInt
	ball += bInt
	for i := 0; i < int(n); i++ {
		scanner.Scan()
		aInt = scanner.Text()[0] - '0'
		a[i] = aInt
		aall += aInt
		scanner.Scan()
		bInt = scanner.Text()[0] - '0'
		b[i] = bInt
		ball += bInt
	}
	dp := make([][][][]Int, 2)
	for i := 0; i < 2; i++ {
		dp[i] = make([][][]Int, aall+1)
		for j := 0; j <= aall; j++ {
			dp[i][j] = make([][][]Int, ball+1)
			for k := 0; k <= ball; k++ {
				dp[i][j][k] = make([][]Int, 2)
				for l := 0; l < 2; l++ {
					dp[i][j][k][l] = 0
				}
			}
		}
	}
	dp[0][0][0][0] = 1
	for i := 1; i <= int(n); i++ {
		id := i % 2
		for asum := aall; asum >= 0; asum-- {
			for cnt := 0; cnt <= ball; cnt++ {
				for p := 0; p < 2; p++ {
					if asum-a[i-1] < 0 {
						continue
					}
					pw := 1
					for use := 0; use < b[i-1]; use++ {
						if cnt-use >= 0 {
							tmp := nCk(cnt, use) * pw
							dp[asum][cnt][p][0] += dp[asum-a[i-1]][cnt-use][p^1][0] * tmp
							dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-use][p^1][1] * tmp
						} else {
							break
						}
						pw = pw * a[i-1]
					}
					if cnt-b[i-1]+1 >= 0 {
						dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-b[i-1]+1][p^1][0] * nCk(cnt, b[i-1]-1) * pw
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
			rev_asum_pow = rev_asum_pow * rev[asum]
			for p := 0; p < 2; p++ {
				x := dp[asum][cnt][p][1] * rev_asum_pow * (cnt + 1) * aall * rev[asum]
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

