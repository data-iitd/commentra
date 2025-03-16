
const MOD = 1e9 + 7

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	coef := make([]int, 0, n)
	for i := 1; i*i <= n; i++ {
		coef = append(coef, n/i-(n/(i+1)))
	}
	coef = append(coef, 1)
	for i := len(coef) - 1; i > 0; i-- {
		coef[i] += coef[i-1]
	}
	dp := make([][]int, k+1)
	for i := range dp {
		dp[i] = make([]int, len(coef))
	}
	dp[0][0] = 1
	for i := 1; i <= k; i++ {
		var tmp int
		for j := len(coef) - 1; j >= 0; j-- {
			tmp += dp[i-1][len(coef)-1-j]
			if tmp >= MOD {
				tmp -= MOD
			}
			dp[i][j] = int64(coef[j]) * int64(tmp) % MOD
		}
	}
	ans := 0
	for _, v := range dp[k] {
		ans += v
		if ans >= MOD {
			ans -= MOD
		}
	}
	fmt.Println(ans)
}
