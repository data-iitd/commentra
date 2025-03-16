
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var N int
	fmt.Fscanf(in, "%d\n", &N)
	A := make([]int64, N+1)
	for i := 1; i <= N; i++ {
		fmt.Fscanf(in, "%d\n", &A[i])
	}
	dp := make([][][]int64, N+1)
	for i := 0; i <= N; i++ {
		dp[i] = make([][]int64, 2)
		for j := 0; j < 2; j++ {
			dp[i][j] = make([]int64, 20)
			for k := 0; k < 20; k++ {
				dp[i][j][k] = -1
			}
		}
	}
	dp[0][0][10] = 0
	for i := 1; i <= N; i++ {
		for j := 6; j <= 14; j++ {
			if dp[i-1][0][j]!= -1 {
				dp[i][1][j+1] = max(dp[i][1][j+1], dp[i-1][0][j]+A[i])
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][0][j])
			}
			if dp[i-1][1][j]!= -1 {
				dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][1][j])
			}
		}
	}
	V := int64(10) + int64(N/2) - int64(N-N/2)
	T1 := dp[N][0][V]
	T2 := dp[N][1][V]
	fmt.Fprintf(out, "%d\n", max(T1, T2))
	out.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

