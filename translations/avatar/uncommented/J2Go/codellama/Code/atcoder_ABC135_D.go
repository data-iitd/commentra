
package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	cs := make([]byte, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&cs[i])
	}
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, 13)
	}
	base := 1
	for i := 0; i < n; i++ {
		if cs[n-1-i] == '?' {
			for pre := 0; pre < 13; pre++ {
				for next := 0; next < 10; next++ {
					dp[i][(base*next+pre)%13] += (i > 0 ? dp[i-1][pre] : (pre == 0 ? 1 : 0))
					dp[i][(base*next+pre)%13] %= int(math.Pow(10, 9) + 7)
				}
			}
		} else {
			next := int(cs[n-1-i] - '0')
			for pre := 0; pre < 13; pre++ {
				dp[i][(base*next+pre)%13] += (i > 0 ? dp[i-1][pre] : (pre == 0 ? 1 : 0))
				dp[i][(base*next+pre)%13] %= int(math.Pow(10, 9) + 7)
			}
		}
		base = base*10 % 13
	}
	fmt.Println(dp[n-1][5])
}

