package main

import (
	"fmt"
	"math/big"
)

const MOD = 1000000007

var fact [1100000]int
var revfact [1100000]int
var rev [1100000]int

func init(){
	m := MOD
	fact[0] = 1
	revfact[0] = 1
	rev[0] = 0
	rev[1] = 1
	for i := 1;i < 1100000;i++{
		fact[i] = fact[i-1] * i % m
		if i > 1{
			rev[i] = m / i * (m-rev[m%i]) % m
		}
		revfact[i] = revfact[i-1] * rev[i] % m
	}
}

func comb(n, k int) int{
	if n < k{
		return 0
	}
	if comb[n][k]!= 0{
		return comb[n][k]
	}
	var res int
	res = fact[n] * revfact[n-k] % MOD * revfact[k] % MOD
	return comb[n][k] = res
}

func mod_pow(x, a int) int{
	if a == 0{
		return 1
	}
	res := mod_pow(x, a/2)
	res = res * res % MOD
	if a % 2{
		res *= x
	}
	return res % MOD
}

func inv(x int) int{
	return mod_pow(x, MOD-2)
}

func main(){
	init()
	var n int
	fmt.Scanf("%d\n", &n)
	var aall, ball int
	var a [440]int
	var b [440]int
	var dp [440][440][2][2]int
	for i := 0;i < n;i++{
		fmt.Scanf("%d %d\n", &a[i], &b[i])
		aall += a[i]
		ball += b[i]
	}

	dp[0][0][0][0] = 1
	for i := 1;i <= n;i++{
		id := i % 2
		for asum := aall;asum >= 0;asum--{
			for cnt := 0;cnt <= ball;cnt++{
				for p := 0;p < 2;p++{
					if asum-a[i-1] < 0{
						continue
					}
					pw := 1
					for use := 0;use < b[i-1];use++{
						if cnt-use >= 0{
							tmp :=  comb(cnt, use) % MOD * pw %  MOD
							dp[asum][cnt][p][0] += dp[asum-a[i-1]][cnt-use][p^1][0] * tmp % MOD
							dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-use][p^1][1] * tmp % MOD
						}
						else{
							break
						}
						pw = pw * a[i-1] % MOD
					}
					if cnt-b[i-1]+1 >= 0{
						dp[asum][cnt][p][1] += dp[asum-a[i-1]][cnt-b[i-1]+1][p^1][0] * comb(cnt, b[i-1]-1) % MOD * pw %  MOD
					}
					dp[asum][cnt][p][0] %= MOD
					dp[asum][cnt][p][1] %= MOD
				}
			}
		}
	}

	var ans int
	for asum := 0;asum <= aall;asum++{
		rev_asum_pow := 1
		for cnt := 0;cnt <= ball;cnt++{
			rev_asum_pow = rev_asum_pow * rev[asum] % MOD
			for p := 0;p < 2;p++{
				x := dp[asum][cnt][p][1] * rev_asum_pow  % MOD * (cnt+1) % MOD * aall % MOD * rev[asum] % MOD
				if p == 1{
					ans += x
				}else{
					ans -= x
				}
				ans %= MOD
			}
		}
	}
	if ans < 0{
		ans += MOD
	}
	fmt.Printf("%d\n", ans)
}

