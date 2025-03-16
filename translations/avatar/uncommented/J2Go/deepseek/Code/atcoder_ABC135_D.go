package main

import (
	"fmt"
	"strings"
)

const MOD = 1000000007

func main() {
	var input string
	fmt.Scan(&input)
	cs := []rune(input)
	dp := make([][]int64, len(cs))
	for i := range dp {
		dp[i] = make([]int64, 13)
	}
	base := int64(1)
	for i := 0; i < len(cs); i++ {
		if cs[len(cs)-1-i] == '?' {
			for pre := 0; pre < 13; pre++ {
				for next := 0; next < 10; next++ {
					dp[i][(base*int64(next)+int64(pre))%13] += (int64(i) > 0 ? dp[i-1][pre] : int64(pre == 0))
					dp[i][(base*int64(next)+int64(pre))%13] %= MOD
				}
			}
		} else {
			next := int(cs[len(cs)-1-i] - '0')
			for pre := 0; pre < 13; pre++ {
				dp[i][(base*int64(next)+int64(pre))%13] += (int64(i) > 0 ? dp[i-1][pre] : int64(pre == 0))
				dp[i][(base*int64(next)+int64(pre))%13] %= MOD
			}
		}
		base = base * 10 % 13
	}
	fmt.Println(dp[len(dp)-1][5])
}
