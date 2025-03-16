
```go
const mod = 1e9 + 7

func main() {
	var n, k int
	fmt.Fscanf(os.Stdin, "%d%d\n", &n, &k)

	coef := make([]int, n)
	for i := 1; i*i <= n; i++ {
		coef[i-1] = (n / i) - (n / (i + 1))
	}
	for i := int(math.Sqrt(float64(n))) + 1; i < n; i++ {
		coef[i-1] = 1
	}

	nn := len(coef)
	dp := make([][]int, k+1)
	for i := range dp {
		dp[i] = make([]int, nn)
	}
	dp[0][0] = 1

	for i := 1; i <= k; i++ {
		tmp := 0
		for j := nn - 1; j >= 0; j-- {
			tmp += dp[i-1][(nn-1)-j]
			if tmp >= mod {
				tmp -= mod
			}
			dp[i][j] = coef[j] * tmp
			if dp[i][j] >= mod {
				dp[i][j] %= mod
			}
		}
	}

	sum := 0
	for _, v := range dp[k] {
		sum += v
		if sum >= mod {
			sum -= mod
		}
	}
	fmt.Println(sum)
}

