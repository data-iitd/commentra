<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import "fmt"

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	var key [1005]int
	var cost [1005]int
	var dp [1005][1005]int
	const INF = 123456789012
	for i := 0; i < 1005; i++ {
		for j := 0; j < 1005; j++ {
			dp[i][j] = INF
		}
	}
	dp[0][0] = 0
	for i := 1; i <= m; i++ {
		var b int
		fmt.Scanf("%d %d", &cost[i], &b)
		for j := 0; j < b; j++ {
			var c int
			fmt.Scanf("%d", &c)
			key[i] += 1 << (c - 1)
		}
	}
	for i := 0; i < (1<<n); i++ {
		for j := 0; j < m; j++ {
			dp[i][j+1] = min(dp[i][j], dp[i][j+1])
			dp[i|key[j+1]][j+1] = min(dp[i|key[j+1]][j+1], dp[i][j]+cost[j+1])
		}
	}
	if dp[(1<<n)-1][m] == INF {
		fmt.Println(-1)
	} else {
		fmt.Println(dp[(1<<n)-1][m])
	}
}

