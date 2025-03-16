package main

import (
 "fmt"
 "strings"
)

func main() {
 new(Main).run()
}

type Main struct{}

const MOD = 1e9 + 7

func (m *Main) run() {
 scanner := bufio.NewScanner(os.Stdin)
 scanner.Scan()
 cs := scanner.Text()
 dp := make([][]int, len(cs))
 for i := range dp {
 dp[i] = make([]int, 13)
 }
 base := 1

 for i := 0; i < len(cs); i++ {
 if cs[len(cs)-1-i] == '?' {
 for pre := 0; pre < 13; pre++ {
 for next := 0; next < 10; next++ {
 dp[i][(base*next+pre)%13] += (if i > 0 { dp[i-1][pre] } else { if pre == 0 { 1 } else { 0 } })
 dp[i][(base*next+pre)%13] %= MOD
 }
 }
 } else {
 next := int(cs[len(cs)-1-i] - '0')
 for pre := 0; pre < 13; pre++ {
 dp[i][(base*next+pre)%13] += (if i > 0 { dp[i-1][pre] } else { if pre == 0 { 1 } else { 0 } })
 dp[i][(base*next+pre)%13] %= MOD
 }
 }
 base = base * 10 % 13
 }

 fmt.Println(dp[len(dp)-1][5])
}

