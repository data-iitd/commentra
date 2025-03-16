
```go
const mod = 1e9 + 7

func main() {
	var l string
	fmt.Scan(&l)
	n := len(l)

	dp := make([][]int64, n+1)
	for i := range dp {
		dp[i] = make([]int64, 2)
	}
	dp[0][0] = 1

	for i, c := range l {
		if c == '0' {
			dp[i+1][0] += dp[i][0]
			dp[i+1][1] += dp[i][1] * 3
		} else {
			dp[i+1][0] += dp[i][0] * 2
			dp[i+1][1] += dp[i][0]
			dp[i+1][1] += dp[i][1] * 3
		}

		dp[i+1][0] %= mod
		dp[i+1][1] %= mod
	}

	result := (dp[n][0] + dp[n][1]) % mod
	fmt.Println(result)
}

