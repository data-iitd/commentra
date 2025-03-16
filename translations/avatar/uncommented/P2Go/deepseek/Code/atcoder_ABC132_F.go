package main

import (
	"bufio"
	"fmt"
	"os"
	"math"
)

const mod = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, k int
	fmt.Fscan(reader, &n, &k)

	coef := []int{}
	for i := 1; i <= int(math.Sqrt(float64(n))); i++ {
		coef = append(coef, (n/i)-(n/(i+1)))
	}
	for i := 0; i < n-len(coef); i++ {
		coef = append(coef, 1)
	}
	for i, j := 0, len(coef)-1; i < j; i, j = i+1, j-1 {
		coef[i], coef[j] = coef[j], coef[i]
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
			tmp += dp[i-1][nn-1-j]
			tmp %= mod
			dp[i][j] = coef[j] * tmp % mod
		}
	}

	sum := 0
	for j := 0; j < nn; j++ {
		sum += dp[k][j]
		sum %= mod
	}
	fmt.Fprintln(writer, sum)
}

