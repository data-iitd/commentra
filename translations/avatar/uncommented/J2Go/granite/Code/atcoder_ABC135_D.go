
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 100000007

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	cs := sc.Text()
	dp := make([][]int64, len(cs))
	for i := range dp {
		dp[i] = make([]int64, 13)
	}
	base := 1
	for i := len(cs) - 1; i >= 0; i-- {
		if cs[i] == '?' {
			for pre := 0; pre < 13; pre++ {
				for next := 0; next < 10; next++ {
					dp[i][(base*next+pre)%13] += (int64(i) > 0? dp[i+1][pre] : (int64(pre) == 0? 1 : 0))
					dp[i][(base*next+pre)%13] %= MOD
				}
			}
		} else {
			next := int(cs[i] - '0')
			for pre := 0; pre < 13; pre++ {
				dp[i][(base*next+pre)%13] += (int64(i) > 0? dp[i+1][pre] : (int64(pre) == 0? 1 : 0))
				dp[i][(base*next+pre)%13] %= MOD
			}
		}
		base = base * 10 % 13
	}
	fmt.Println(dp[0][5])
}

// 