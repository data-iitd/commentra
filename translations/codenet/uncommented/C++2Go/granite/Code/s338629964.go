
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var buf bytes.Buffer

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	var a, b int
	var asum, bsum int

	dp := make([][][][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([][][]int, asum+1)
		for j := 0; j <= asum; j++ {
			dp[i][j] = make([][][]int, bsum+1)
			for k := 0; k <= bsum; k++ {
				dp[i][j][k] = make([][]int, 2)
				for l := 0; l < 2; l++ {
					dp[i][j][k][l] = make([]int, 2)
				}
			}
		}
	}

	dp[0][0][0][0][0] = 1

	for i := 1; i <= n; i++ {
		fmt.Fscanf(reader, "%d %d\n", &a, &b)
		asum += a
		bsum += b
		for j := asum; j >= a; j-- {
			for k := bsum; k >= b; k-- {
				for l := 0; l < 2; l++ {
					for m := 0; m < 2; m++ {
						var tmp int
						var p int
						for p = 0; p <= b && p <= k; p++ {
							tmp = int(mul(tmp, int64(a), MOD))
							tmp = add(tmp, int64(nCk(k, p)), MOD)
							dp[i][j][k][l][m] = add(dp[i][j][k][l][m], int64(dp[i-1][j-a][k-p][l^1][m][0]), MOD)
							if p < b {
								dp[i][j][k][l][m] = add(dp[i][j][k][l][m], int64(dp[i-1][j-a][k-p][l^1][m][1])*int64(tmp), MOD)
							}
						}
					}
				}
			}
		}
	}

	var ans int

	for j := 0; j <= asum; j++ {
		var rev_asum_pow int64 = 1
		for k := 0; k <= bsum; k++ {
			rev_asum_pow = mul(rev_asum_pow, inv(int64(j), MOD), MOD)
			for l := 0; l < 2; l++ {
				for m := 0; m < 2; m++ {
					if m == 1 {
						ans = add(ans, int(mul(int64(dp[n][j][k][l][m]), rev_asum_pow, MOD)*int64(k+1)*int64(asum)%MOD), MOD)
					} else {
						ans = sub(ans, int(mul(int64(dp[n][j][k][l][m]), rev_asum_pow, MOD)*int64(k+1)*int64(asum)%MOD), MOD)
					}
				}
			}
		}
	}

	fmt.Fprintf(&buf, "%d\n", ans)

	fmt.Print(buf.String())
}

func add(a, b, mod int64) int64 {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func sub(a, b, mod int64) int64 {
	return add(a, mod-b, mod)
}

func mul(a, b, mod int64) int64 {
	r := int64(0)
	for a > 0 {
		if a&1 == 1 {
			r += b
			if r >= mod {
				r -= mod
			}
		}
		a >>= 1
		b <<= 1
		if b >= mod {
			b -= mod
		}
	}
	return r
}

func inv(a, mod int64) int64 {
	b := mod
	u := int64(1)
	v := int64(0)
	for b > 0 {
		t := a / b
		a -= t * b
		a, b = b, a
		u -= t * v
		u, v = v, u
	}
	u %= mod
	if u < 0 {
		u += mod
	}
	return u
}

func nCk(n, k int) int {
	if k < 0 || n < k {
		return 0
	}
	k = min(k, n-k)
	c := 1
	r := 1
	for i := 0; i < k; i++ {
		c *= n - i
		r *= i + 1
		c /= r
	}
	return c
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

const MOD = 998244353

