package main

import (
	"fmt"
)

const MOD = 1e9 + 7

func main() {
	var cs string
	fmt.Scan(&cs)
	run(cs)
}

func run(cs string) {
	n := len(cs)
	dp := make([][13]int64, n)
	base := 1

	for i := 0; i < n; i++ {
		if cs[n-1-i] == '?' {
			for pre := 0; pre < 13; pre++ {
				for next := 0; next < 10; next++ {
					if i > 0 {
						dp[i][(base*next+pre)%13] += dp[i-1][pre]
					} else {
						if pre == 0 {
							dp[i][(base*next+pre)%13] += 1
						}
					}
					dp[i][(base*next+pre)%13] %= int64(MOD)
				}
			}
		} else {
			next := cs[n-1-i] - '0'
			for pre := 0; pre < 13; pre++ {
				if i > 0 {
					dp[i][(base*int(next)+pre)%13] += dp[i-1][pre]
				} else {
					if pre == 0 {
						dp[i][(base*int(next)+pre)%13] += 1
					}
				}
				dp[i][(base*int(next)+pre)%13] %= int64(MOD)
			}
		}
		base = (base * 10) % 13
	}

	fmt.Println(dp[n-1][5])
}

// <END-OF-CODE>
