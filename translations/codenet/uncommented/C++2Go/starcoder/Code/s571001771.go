package main
import "fmt"

func main() {
	var n, m int
	fmt.Scanf("%d %d\n", &n, &m)
	var key [1005]int
	var cost [1005]int
	var dp [1005][1<<12]int
	for i := 0; i < 1005; i++ {
		for j := 0; j < 1<<12; j++ {
			dp[i][j] = 123456789012
		}
	}
	dp[0][0] = 0
	for i := 0; i < m; i++ {
		var b int
		fmt.Scanf("%d %d\n", &cost[i], &b)
		for j := 0; j < b; j++ {
			var c int
			fmt.Scanf("%d\n", &c)
			key[i] += 1 << (c - 1)
		}
	}
	for i := 0; i < (1 << n); i++ {
		for j := 0; j < m; j++ {
			dp[j+1][i] = min(dp[j+1][i], dp[j][i])
			dp[j+1][i|key[j+1]] = min(dp[j+1][i|key[j+1]], dp[j][i]+cost[j+1])
		}
	}
	if dp[m][(1<<n)-1] == 123456789012 {
		fmt.Println(-1)
	} else {
		fmt.Println(dp[m][(1<<n)-1])
	}
}

