

package main

import (
 "bufio"
 "fmt"
 "os"
 "strconv"
)

const MOD = 1000000007

func main() {
 sc := bufio.NewScanner(os.Stdin)
 sc.Scan()
 s := sc.Text()
 dp := make([][]int64, len(s))
 for i := range dp {
 dp[i] = make([]int64, 13)
 }
 base := 1
 for i := len(s) - 1; i >= 0; i-- {
 if s[i] == '?' {
 for pre := 0; pre < 13; pre++ {
 for next := 0; next < 10; next++ {
 dp[i][(base*next+pre)%13] += (int64(i) > 0? dp[i+1][pre] : (int64(pre) == 0? 1 : 0))
 dp[i][(base*next+pre)%13] %= MOD
 }
 }
 } else {
 next, _ := strconv.Atoi(string(s[i]))
 for pre := 0; pre < 13; pre++ {
 dp[i][(base*next+pre)%13] += (int64(i) > 0? dp[i+1][pre] : (int64(pre) == 0? 1 : 0))
 dp[i][(base*next+pre)%13] %= MOD
 }
 }
 base = base * 10 % 13
 }
 fmt.Println(dp[0][5])
}

