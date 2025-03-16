
package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    var s string
    fmt.Fscanf(in, "%s\n", &s)
    n := len(s)
    if n == 1 {
        if s[0] == '5' || s[0] == '?' {
            fmt.Fprintln(out, 1)
        } else {
            fmt.Fprintln(out, 0)
        }
        out.Flush()
        return
    }
    dp := make([][]int, n)
    for i := range dp {
        dp[i] = make([]int, 13)
    }
    for i := 0; i < n; i++ {
        if i == 0 {
            if s[i]!= '?' {
                dp[i][s[i]-'0']++
            } else {
                for j := 0; j < 10; j++ {
                    dp[i][j]++
                }
            }
        } else {
            if s[i]!= '?' {
                for j := 0; j < 13; j++ {
                    dp[i][(j*10+s[i]-'0')%13] += dp[i-1][j]
                }
            } else {
                for j := 0; j < 10; j++ {
                    for k := 0; k < 13; k++ {
                        dp[i][(k*10+j)%13] += dp[i-1][k]
                    }
                }
            }
            for j := 0; j < 13; j++ {
                dp[i][j] %= 100000007
            }
        }
    }
    fmt.Fprintln(out, dp[n-1][5])
    out.Flush()
}

