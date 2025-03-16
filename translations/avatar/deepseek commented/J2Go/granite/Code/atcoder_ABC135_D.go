
package main

import (
    "bufio"
    "fmt"
    "os"
)

const MOD = 1000000007

func main() {
    reader := bufio.NewReader(os.Stdin)
    s, _ := reader.ReadString('\n')
    s = s[:len(s)-1]

    dp := make([][]int64, len(s))
    for i := range dp {
        dp[i] = make([]int64, 13)
    }

    base := 1
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == '?' {
            for pre := 0; pre < 13; pre++ {
                for next := 0; next < 10; next++ {
                    dp[i][(base*next+pre)%13] += dp[i+1][pre]
                    dp[i][(base*next+pre)%13] %= MOD
                }
            }
        } else {
            next := int(s[i] - '0')
            for pre := 0; pre < 13; pre++ {
                dp[i][(base*next+pre)%13] += dp[i+1][pre]
                dp[i][(base*next+pre)%13] %= MOD
            }
        }
        base = base * 10 % 13
    }

    fmt.Println(dp[0][5])
}

// END-OF-CODE