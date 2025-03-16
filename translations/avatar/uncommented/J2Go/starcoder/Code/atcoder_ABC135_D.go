package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var s string
	s, _ = reader.ReadString('\n')
	s = strings.TrimSpace(s)
	var dp [][]int
	dp = make([][]int, len(s))
	for i := range dp {
		dp[i] = make([]int, 13)
	}
	var base int = 1
	for i := 0; i < len(s); i++ {
		if s[len(s)-1-i] == '?' {
			for pre := 0; pre < 13; pre++ {
				for next := 0; next < 10; next++ {
					dp[i][(base*next+pre)%13] += (i > 0? dp[i-1][pre] : (pre == 0? 1 : 0))
					dp[i][(base*next+pre)%13] %= 1000000007
				}
			}
		} else {
			next, _ := strconv.Atoi(string(s[len(s)-1-i]))
			for pre := 0; pre < 13; pre++ {
				dp[i][(base*next+pre)%13] += (i > 0? dp[i-1][pre] : (pre == 0? 1 : 0))
				dp[i][(base*next+pre)%13] %= 1000000007
			}
		}
		base = base*10 % 13
	}
	fmt.Println(dp[len(s)-1][5])
}

