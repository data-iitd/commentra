package main

import "fmt"

func main() {
	var n, k int
	fmt.Scan( &n, &k )
	coef := make( []int, n )
	for i := 1 ; i < int( n ** 0.5 ) + 1 ; i++ {
		coef[i] = ( n / i ) - ( n / ( i + 1 ) )
	}
	coef = append( coef, make( []int, n - len( coef ) )... )
	coef = coef[ : len( coef ) - 1 : -1 ]
	nn := len( coef )
	dp := make( [][]int, k + 1 )
	for i := range dp {
		dp[i] = make( []int, nn )
	}
	dp[0][0] = 1
	for i := 1 ; i < k + 1 ; i++ {
		tmp := 0
		for j := nn - 1 ; j >= 0 ; j-- {
			tmp += dp[i-1][nn-1-j]
			tmp %= 1000000007
			dp[i][j] = coef[j] * tmp
			dp[i][j] %= 1000000007
	}
	fmt.Println( dp[k][0] )
}

