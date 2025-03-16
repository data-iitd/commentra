package main
import "fmt"

func main() {
	var (
		n int
		S string
	)
	fmt.Scanf("%d\n%s", &n, &S)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 13)
	}
	dp[0][int(S[0])-1] = 1
	for i := 1; i < n; i++ {
		for j := 0; j < 10; j++ {
			for k := 0; k < 13; k++ {
				dp[i][(k*10+j)%13] += dp[i-1][k]
			}
		}
	}
	fmt.Println(dp[n-1][5])
}
